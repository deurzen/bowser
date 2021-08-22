#include "util.hh"

#include <QString>
#include <QUrl>

#include <vector>
#include <string>

char*
convert_new(const std::string& s)
{
    char* raw = new char[s.size() + 1];
    std::strcpy(raw, s.c_str());
    return raw;
}

const char*
convert(const std::string& s)
{
    return s.c_str();
}

QString
safe_displaystring(QUrl url)
{
    auto host = url.host(QUrl::FullyEncoded);
    std::string host_str = host.toStdString();

    auto pos = 0u;
    auto end = host_str.find(".");

    while (end != std::string::npos) {
        if (!host_str.substr(pos, end - pos).rfind("xn--", pos) && host.compare(url.host(QUrl::FullyDecoded)))
            return "(" + host + ") " + url.toDisplayString();
        pos = end + 1;
        end = host_str.find(".");
    }

    return url.toDisplayString();
}
