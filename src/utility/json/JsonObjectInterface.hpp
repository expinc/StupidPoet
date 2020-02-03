#pragma once


#include "JsonTuple.hpp"


namespace StupidPoet
{
    class JsonObjectInterface
    {
    public:
        virtual bool        hasMember(const UChar* name) = 0;
        virtual JsonTuple   getMember(const UChar* name) = 0;

        virtual void        addMemberValue(const UChar* name, bool value) = 0;
        virtual void        addMemberValue(const UChar* name, int value) = 0;
        virtual void        addMemberValue(const UChar* name, double value) = 0;
        virtual void        addMemberValue(const UChar* name, const UChar* value) = 0;
        virtual JsonArray   addMemberArray(const UChar* name) = 0;
        virtual JsonObject  addMemberObject(const UChar* name) = 0;
        virtual void        addMemberNull(const UChar* name) = 0;
    };
}
