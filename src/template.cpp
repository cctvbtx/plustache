/**
 * @file template.cpp
 * @brief plustache template
 * @author Daniel Schauenberg <d@unwiredcouch.com>
 * @version 0.1
 * @date 2010-03-12
 */

#include <template.hpp>

void template_t::hello_world()
{
    cout << "Hello World!\n";
}

template_t::template_t()
{
    otag = "\\{\\{";
    ctag = "\\}\\}";
    tag.assign(otag + "(.+)" + ctag);
}

template_t::~template_t()
{

}

string template_t::render(string tmplate, context ctx)
{
    string ret = "";
    return ret;
}

string template_t::render(string tmplate, map<string, string> ctx)
{
    string ret = "";
    boost::cmatch matches;
    if (boost::regex_search(tmplate.c_str(), matches, tag,
                            boost::match_default | boost::format_all))
    {
        string key(matches[1].first, matches[1].second);
        string repl = ctx[key];
        ret = regex_replace(tmplate, tag, repl,
                        boost::match_default | boost::format_all);
    }
    return ret;
}

