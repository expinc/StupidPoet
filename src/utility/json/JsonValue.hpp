#pragma once


#include "infra/UStr.hpp"
#include <rapidjson/document.h>
#include <rapidjson/encodings.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>


namespace StupidPoet
{
    using namespace rapidjson;


    class JsonArray;
    class JsonDoc;
    class JsonObject;


    class JsonValue
    {
        friend class JsonArray;
        friend class JsonDoc;
        friend class JsonObject;

    public:
        enum ValueType
        {
            Null,
            Bool,
            Int,
            Double,
            Str,
            Array,
            Object
        };

    protected:
        static ValueType    getValueType(const GenericValue<UTF16<UChar>>& rapidValue);

    protected:
        GenericValue<UTF16<UChar>>* _value;
        MemoryPoolAllocator<>*  _allocator;
        ValueType  _valueType;

    public:
        JsonValue(GenericValue<UTF16<UChar>>* value, MemoryPoolAllocator<>* allocator) :
            _value(value),
            _allocator(allocator),
            _valueType(getValueType(*value))
        {}

        inline bool         isValid() const { return _value && _allocator; }
        inline ValueType    getType() const { return _valueType; }

        bool        getBool();
        int         getInt();
        double      getDouble();
        UStr        getStr();
        JsonArray   getArray();
        JsonObject  getObject();
    };
}
