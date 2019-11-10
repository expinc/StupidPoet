#pragma once


#include <string>


namespace StupidPoet
{
    typedef char16_t    UChar;


    class UStr : public std::basic_string<UChar>
    {
    public:
        static UStr fromUtf8(const char* utf8);
        static std::string  toUtf8(const UChar* uStr);
        static std::wstring toWStr(const UStr& uStr);

        UStr() = default;
        UStr(const std::basic_string<UChar>& other) : std::basic_string<UChar>(other) {}
    };
}
