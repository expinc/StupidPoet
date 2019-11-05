#pragma once


#include "infra/ExceptionBase.hpp"


namespace StupidPoet
{
    class ModelException : public ExceptionBase
    {
    public:
        inline ModelException(const UChar* what) : ExceptionBase(what) {}
    };
}
