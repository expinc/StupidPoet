#pragma once


#include "ExceptionBase.hpp"


namespace StupidPoet
{
    class InfraException : public ExceptionBase
    {
    public:
        inline InfraException(const UChar* what) : ExceptionBase(what) {}
    };
}
