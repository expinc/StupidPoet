#pragma once


#include <exception>
#include "UStr.hpp"


namespace StupidPoet
{
    class ExceptionBase
    {
    protected:
        UStr    _what;

    public:
        inline ExceptionBase(const UChar* what) { _what.assign(what); }
        inline const UChar*    What() { return _what.c_str(); }
    };
}
