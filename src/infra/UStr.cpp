#include "UStr.hpp"

#include <codecvt>


namespace StupidPoet
{
    UStr UStr::fromUtf8(const char* utf8)
    {
        static std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> s_convert;
        return s_convert.from_bytes(utf8);
    }


    std::string  UStr::toUtf8(const UChar* uStr)
    {
        static std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> s_convert;
        return s_convert.to_bytes(uStr);
    }


    std::wstring UStr::toWStr(const UStr& uStr)
    {
        #ifdef  _WIN32
        return std::move( std::wstring(uStr.begin(), uStr.end()) );
        #endif
    }
}
