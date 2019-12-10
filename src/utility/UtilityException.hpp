#pragma once


#include "infra/ExceptionBase.hpp"


namespace StupidPoet
{
    class UtilityException : public ExceptionBase
    {
    public:
        inline UtilityException(const UChar* what) : ExceptionBase(what) {}
    };
}
