#ifndef __BOWSER__UTIL__GUARD__
#define __BOWSER__UTIL__GUARD__

#include <cstring>
#include <string>

char* convert_new(const ::std::string&);
const char* convert(const ::std::string&);

class QString;
class QUrl;
QString safe_displaystring(QUrl);

#endif//__BOWSER__UTIL__GUARD__
