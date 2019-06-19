#include "util.hh"


char*
convert_new(const ::std::string& s)
{
    char* raw = new char[s.size() + 1];
    ::std::strcpy(raw, s.c_str());
    return raw;
}

const char*
convert(const ::std::string& s)
{
    return s.c_str();
}
