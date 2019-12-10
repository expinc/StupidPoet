#pragma once


#include "JsonTuple.hpp"


namespace StupidPoet
{
    class JsonObjectInterface
    {
    public:
        virtual JsonTuple   getMember(const UChar* name) = 0;
        virtual void    addMember(const UChar* name, bool value) = 0;
        virtual void    addMember(const UChar* name, int value) = 0;
        virtual void    addMember(const UChar* name, double value) = 0;
        virtual void    addMember(const UChar* name, const UChar* value) = 0;
        virtual void    addMember(const UChar* name, const JsonValue& value) = 0;
    };
}
