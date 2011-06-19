#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/fusion/adapted/struct/define_struct.hpp>
#include <boost/foreach.hpp>

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

namespace phoenix = boost::phoenix;
namespace spirit  = boost::spirit;
namespace qi      = spirit::qi;

typedef std::string::iterator file_iterator;

using spirit::ascii::space_type;

#define DEBUG_NODE(r)                                              \
r.name(#r);                                                        \
if(debug)                                                          \
    qi::debug(r);                                                  \

qi::rule<file_iterator, space_type, std::string()> comment
    =   (   *qi::lexeme[qi::lit("//") >> *(qi::char_ - qi::eol)]                            )
    |   (   *qi::lexeme[qi::lit("/*") >> *(qi::char_ - qi::char_("*/")) >> qi::lit("*/")]   )
;

BOOST_FUSION_DEFINE_STRUCT(, file_info_t,
    (std::string, include_guard)
    (std::vector<std::string>, includes)
);

struct prologue : qi::grammar<file_iterator, space_type, file_info_t()>
{
    prologue(bool debug_) : base_type(root), debug(debug_)
    {
        root
            =   qi::omit[comment]
                >> qi::lit("#ifndef") >> qi::lexeme[+(qi::char_ - qi::eol)]
                >> qi::lit("#define") >> qi::omit[qi::lexeme[+(qi::char_ - qi::eol)]]
                >> *include
        ;
        
        include
            =   qi::lit("#include") >> qi::lexeme[qi::lit('<') >> +(qi::char_ - qi::char_('>')) >> qi::lit('>')]
        ;
        
        DEBUG_NODE(root)
        DEBUG_NODE(comment)
        DEBUG_NODE(include)
    }
    
    qi::rule<file_iterator, space_type, file_info_t()> root;
    qi::rule<file_iterator, space_type, std::string()> include;
    
    bool debug;
};

struct epilogue : qi::grammar<file_iterator, space_type>
{
    epilogue(bool debug_) : base_type(root), debug(debug_)
    {
        root
            =   qi::lit("#endif")
        ;
    }
    
    qi::rule<file_iterator, space_type> root;
    
    bool debug;
};

BOOST_FUSION_DEFINE_STRUCT(, dispatch_t,
    (std::string, tag)
    (std::string, site)
    (std::vector<std::string>, template_args)
    (std::vector<std::string>, args)
);

std::ostream& operator<<(std::ostream& os, dispatch_t const& dispatch)
{
    os << "  tag: " << dispatch.tag << "\n";
    os << "  site: " << dispatch.site << "\n";
    os << "  template_args: { " << dispatch.template_args[0];
    for(std::size_t i=1; i!=dispatch.template_args.size(); ++i)
        os << ", " << dispatch.template_args[i];
    os << " }\n";
    os << "  args: { " << dispatch.args[0];
    for(std::size_t i=1; i!=dispatch.args.size(); ++i)
        os << ", " << dispatch.args[i];
    os << " }\n";
    return os;
}

BOOST_FUSION_DEFINE_STRUCT(, call_t,
    (std::string, comment)
    (dispatch_t, dispatch)
    (std::string, result)
    (std::string, code)
);

std::ostream& operator<<(std::ostream& os, call_t const& call)
{
    os << "comment: " << call.comment << "\n";
    os << "dispatch:\n" << call.dispatch;
    os << "result: " << call.result << "\n";
    os << "code: " << call.code << "\n";
    return os;
}

struct specialization : qi::grammar<file_iterator, space_type, call_t()>
{
    specialization(bool debug_) : base_type(root), debug(debug_)
    {
        using namespace qi::labels;
        
        root
            =   (   comment
                >>  register_dispatch
                >>  qi::lit("namespace") >> qi::lit("nt2")
                >>  qi::lit('{')
                    >>  qi::lit("namespace") >> qi::lit("ext")
                    >>  qi::lit('{')
                        >>  call
                    >>  qi::lit('}')
                >>  qi::lit('}')
                ) [ _val = phoenix::construct<call_t>(_1, _2, phoenix::at_c<0>(_3), phoenix::at_c<1>(_3)) ]
        ;
        
        register_dispatch
            =   qi::lit("NT2_REGISTER_DISPATCH")
                >>  qi::lit('(')
                    >> full_name >> qi::lit(',') // tag
                    >> full_name >> qi::lit(',') // site
                    >> *(qi::lit('(') >> name >> qi::lit(')')) >> qi::lit(',') // template args
                    >> *(qi::lit('(') >> full_name >> qi::lit(')')) // args
                >>  qi::lit(')')
        ;
        
        call
            =   template_declare
                >>  qi::lit("struct") >> qi::lit("call")
                >> qi::omit
                [
                    qi::lit('<')
                        >> full_name
                        >> qi::lit('(')
                            >> (full_name % ',')
                        >> qi::lit(')') >> qi::lit(',')
                        >>  full_name >> qi::lit(',')
                        >>  qi::lit("Dummy")
                    >>  qi::lit('>')
                ]
                >>  qi::lit(':') >> qi::lit("callable")
                >>  qi::lit('{')
                    >> result
                    >> operator_
                >>  qi::lit('}') >> qi::lit(';')
        ;
        
        result
            =   (   qi::lit("typedef") >> full_name >> qi::lit("result_type")   )
            |   (   template_declare
                    >>  qi::lit("struct") >> qi::lit("result") >> qi::lit(';')
                    >>  template_declare >> qi::lit("struct") >> qi::lit("result")
                    >>  qi::omit
                    [
                        qi::lit('<')
                            >> full_name
                            >> qi::lit('(')
                                >> (full_name % ',')
                            >> qi::lit(')')
                        >> qi::lit('>')
                    ]
                    >>  (   (   qi::lit(':')
                                >> full_name >> qi::lit('{') >> qi::lit('}')
                            )   [ _val = "typename " + _1 + "::type"    ]
                        |   (   qi::lit('{')
                                >>  qi::lit("typedef") >> full_name >> qi::lit("type") >> qi::lit(';')
                                >>  qi::lit('}')
                            )
                        )
                )
                >> qi::lit(';')
        ;
        
        operator_
            =   qi::lit("NT2_FUNCTOR_CALL(") >> qi::omit[qi::int_] >> qi::lit(')')
                >> qi::lit('{')
                >> qi::no_skip[code]
                >> qi::lit('}')
        ;

        template_declare
            =   qi::lit("template")
                >> qi::lit('<')
                    >>  (   (   qi::lit("class")
                            |   qi::lit("typename")
                            ) >> name
                        ) % ','
                >> qi::lit('>')
        ;
        
        name = qi::raw[+qi::char_("a-zA-Z0-9_")];
        
        full_name
            =   qi::raw[
                    (   qi::lit('(') >> (full_name % qi::char_(',')) >> qi::lit(')')   )
                    |   (   +(qi::char_("a-zA-Z0-9_:"))
                    >> -(   qi::char_('<') >> (full_name % qi::char_(',')) >> qi::char_('>')   )
                    )
                ]
        ;
        
        code
            =   (   qi::lit('{') >> code >> qi::lit('}')        )
            |   (   +(qi::char_ - qi::char_("{}"))  >> -code    )
        ;
            
        DEBUG_NODE(root)
        DEBUG_NODE(register_dispatch)
        DEBUG_NODE(call)
        DEBUG_NODE(result)
        DEBUG_NODE(operator_)
        
        DEBUG_NODE(template_declare)
        DEBUG_NODE(name)
        DEBUG_NODE(full_name)
        DEBUG_NODE(code)
    }

    
    qi::rule<file_iterator, space_type, call_t()> root;
    qi::rule<file_iterator, space_type, dispatch_t()> register_dispatch;
    qi::rule<file_iterator, space_type, boost::fusion::vector2<std::string, std::string>()> call;
    qi::rule<file_iterator, space_type, std::string()> result;
    qi::rule<file_iterator, space_type, std::string()> operator_;
    
    qi::rule<file_iterator, space_type> template_declare;
    qi::rule<file_iterator, space_type, std::string()> name;
    qi::rule<file_iterator, space_type, std::string()> full_name;
    qi::rule<file_iterator, std::string()> code;
    
    bool debug;
};

int main(int argc, char* argv[])
{
    bool debug = false;
    int pos = 1;
    for(int i=1; i!=argc; ++i)
    {
        if(argv[i] == std::string("--debug"))
        {
            debug = true;
            if(i <= pos)
                ++pos;
        }
    }
    
    if(pos >= argc)
    {
        std::cerr << "No file argument" << std::endl;
        return 1;
    }
    
    std::fstream f(argv[pos]);
    if(!f)
    {
        std::cerr << "File " << argv[1] << " could not be opened" << std::endl;
        return 1;
    }
    
    std::stringstream ss;
    ss << f.rdbuf();
    std::string buf = ss.str();
    
    std::string::iterator it = buf.begin();
    
    file_info_t file_info;
    bool b = qi::phrase_parse(it, buf.end(), prologue(debug), spirit::ascii::space, file_info);
    if(!b)
    {
        std::cerr << "Could not parse prologue in " << argv[pos] << std::endl;
        return 1;
    }
    
    std::cout << "include guard: " << file_info.include_guard << "\n";
    std::cout << "includes: ";
    BOOST_FOREACH(std::string& include, file_info.includes)
        std::cout << include << "\n          ";
    std::cout << std::endl;
    
    for(;;)
    {
        call_t call;
        bool b = qi::phrase_parse(it, buf.end(), specialization(debug), spirit::ascii::space, call);
        if(!b)
            break;
            
        std::cout << "--- match ---\n";
        std::cout << call << std::endl;
    }
    
    b = qi::phrase_parse(it, buf.end(), epilogue(debug), spirit::ascii::space);
    
    if(!b)
    {
        std::cerr << "Parsing of file " << argv[pos] << " incomplete" << std::endl;
        return 1;
    }
    return 0;
}
