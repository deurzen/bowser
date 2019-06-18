#include "parse.hh"
#include "util.hh"

void
parser_t::parse()
{
    for (size_t i = 0; i < opts.size(); ++i) {
        if (opts[i].rfind("--", 0) != ::std::string::npos) {
            ::std::string optflag = opts[i].substr(2);
            if (!optmap.count(optflag)) continue;
            option_t opt = optmap[optflag];
            if (opt.has_value && i+1 < opts.size()) {
                setopt(optflag, opts[i+1]);
                ++i;
            } else if (!opt.flag.empty() && !opt.has_value)
                setopt(optflag);
        } else if (opts[i].rfind("-", 0) != ::std::string::npos) {
            ::std::string optflags = opts[i].substr(1);
            for (auto& optflag : optflags)
                setopt(::std::string(1, optflag));
        }
    }
}

void
parser_t::setopt(::std::string flag, ::std::string value)
{
    for (auto& opt : optlist)
        if (!opt.flag.compare(flag)) {
            opt.set = true;
            opt.value = value;
        }
}

::std::pair<int, ::std::vector<char*>>
parser_t::getargs()
{
    ::std::vector<char*> raw;
    for (auto& s : args)
        raw.push_back(convert_new(s));

    return {raw.size(), raw};
}
