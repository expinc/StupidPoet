#pragma once


#include <string>


namespace StupidPoet
{
    typedef char16_t    UChar;


    class UCharAuxiliary final
    {
    public:
        static bool isChinese(UChar ch) { return ch >= 0x4e00 && ch <= 0x9fff; }
    };


    class UStr final : public std::basic_string<UChar>
    {
    public:
        static UStr fromUtf8(const char* utf8);
        static std::string  toUtf8(const UChar* uStr);
        static std::wstring toWStr(const UStr& uStr);

        UStr() = default;
        inline UStr(const size_t count, const UChar ch) : std::basic_string<UChar>(count, ch) {}
        inline UStr(const std::basic_string<UChar>& other) : std::basic_string<UChar>(other) {}
    };
}
