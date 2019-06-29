#ifndef __BOWSER__PARSE__GUARD__
#define __BOWSER__PARSE__GUARD__

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

enum option_type_t { longopt, shortopt };

struct option_t
{
    option_t() = default;

    option_t(option_type_t _type)
        : type(_type),
          has_value(false),
          set(false)
    {}

    option_t(option_type_t _type, ::std::string _flag,
        ::std::string _desc, bool _has_value = false)
        : flag(_flag),
          desc(_desc),
          has_value(_has_value),
          set(false)
    {}

    option_type_t type = shortopt;
    ::std::string flag;
    ::std::string desc;
    ::std::string value;
    bool has_value, set;
};


class parser_t
{
public:
    parser_t(int argc, char** argv)
        : m_opts(argv, argv + argc),
          m_optlist({
              // short options           flag           description
              { option_type_t::shortopt, "h",           "print help message"                 },
              { option_type_t::shortopt, "v",           "print version information and quit" },

              // long options            flag           description                           has value
              { option_type_t::longopt,  "help",        "print help message",                 false },
              { option_type_t::longopt,  "version",     "print version information and quit", false },
              { option_type_t::longopt,  "no-config",   "do not load configuration file",     false },
              { option_type_t::longopt,  "config-path", "path to configuration file",         true  },
          })
    {
        for (auto& opt : m_optlist)
            m_optmap[opt.flag] = opt;

        ::std::vector<::std::string>::iterator it;
        if ((it = ::std::find(m_opts.begin(), m_opts.end(), "--")) != m_opts.end()) {
            ::std::move(it + 1, m_opts.end(), ::std::back_inserter(m_args));
            m_opts.erase(it, m_opts.end());
        }
    }

    void parse();
    void setopt(::std::string, ::std::string = "");

    ::std::pair<int, ::std::vector<char*>> getargs();

private:
    ::std::vector<::std::string> m_opts;
    ::std::vector<::std::string> m_args;

    ::std::vector<option_t> m_optlist;
    ::std::unordered_map<::std::string, option_t> m_optmap;

};

#endif//__BOWSER__PARSE__GUARD__
