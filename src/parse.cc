#include "parse.hh"
#include "util.hh"

void
parser_t::parse()
{
    for (size_t i = 0; i < m_opts.size(); ++i) {
        if (m_opts[i].rfind("--", 0) != ::std::string::npos) {
            ::std::string optflag = m_opts[i].substr(2);
            if (!m_optmap.count(optflag)) continue;
            option_t opt = m_optmap[optflag];
            if (opt.has_value && i+1 < m_opts.size()) {
                setopt(optflag, m_opts[i+1]);
                ++i;
            } else if (!opt.flag.empty() && !opt.has_value)
                setopt(optflag);
        } else if (m_opts[i].rfind("-", 0) != ::std::string::npos) {
            ::std::string optflags = m_opts[i].substr(1);
            for (auto& optflag : optflags)
                setopt(::std::string(1, optflag));
        }
    }
}

void
parser_t::setopt(::std::string flag, ::std::string value)
{
    for (auto& opt : m_optlist)
        if (!opt.flag.compare(flag)) {
            opt.set = true;
            opt.value = value;
        }
}

::std::pair<int, ::std::vector<char*>>
parser_t::getargs()
{
    ::std::vector<char*> raw;
    for (auto& s : m_args)
        raw.push_back(convert_new(s));

    return {raw.size(), raw};
}
