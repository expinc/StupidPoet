#pragma once


#include "JsonValue.hpp"


namespace StupidPoet
{
    class JsonTuple : public JsonValue
    {
    protected:
        UStr    _name;

    public:
        inline const UStr& getName() const { return _name; }

    protected:
        JsonTuple(
            const UChar* name,
            GenericValue<UTF16<char16_t>>& value,
            MemoryPoolAllocator<>& allocator) :
            JsonValue(value, allocator),
            _name(name)
        {}

    friend class JsonObject;
    friend class JsonDoc;
    };
}
