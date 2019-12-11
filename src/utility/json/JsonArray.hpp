#pragma once


#include "JsonValue.hpp"


namespace StupidPoet
{
    class JsonArray : public JsonValue
    {
    protected:
        ValueType    _elemType;

    public:
        inline JsonValue    at(size_t index) { return JsonValue(_value[index], _allocator); }

        bool    pushBack(const bool value);
        bool    pushBack(const int value);
        bool    pushBack(const double value);
        bool    pushBack(const UStr& value);
        bool    pushBack(const JsonValue& value);

        JsonArray& operator=(const JsonArray& other);

    protected:
        JsonArray(GenericValue<UTF16<UChar>>& value, MemoryPoolAllocator<>& allocator) :
            JsonValue(value, allocator),
            _elemType(getValueType(*(value.Begin())))
        {}

        friend class JsonValue;
    };
}
