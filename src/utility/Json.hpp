#pragma once


#include "infra/UStr.hpp"
#include <rapidjson/document.h>
#include <rapidjson/encodings.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>


namespace StupidPoet
{
    using namespace rapidjson;


    class JsonObject;
    class JsonArray;


    class JsonElem
    {
    public:
        enum ElemType
        {
            Bool,
            Int,
            Float,
            Str,
            Object,
            Array
        };

    protected:
        GenericValue<UTF16<char16_t>>& _elem;
        MemoryPoolAllocator<>&  _allocator;
        ElemType  _elemType;

    public:
        inline ElemType    getElemType() { return _elemType; }
        bool    getValue(bool& value);
        bool    getValue(int& value);
        bool    getValue(float& value);
        bool    getValue(UStr& value);
        bool    getValue(JsonObject& value);
        bool    getValue(JsonArray& value);

    protected:
        JsonElem(GenericValue<UTF16<char16_t>>& elem, MemoryPoolAllocator<>& allocator);
    };


    class JsonTuple : public JsonElem
    {
    protected:
        UStr    _name;

    public:
        const UStr& getName();

    protected:
        JsonTuple(
            const UStr& name,
            GenericValue<UTF16<char16_t>>& elem,
            MemoryPoolAllocator<>& allocator);
    };


    class JsonArray : public JsonElem
    {
    public:
        JsonElem    at(size_t index);

    protected:
        JsonArray(GenericValue<UTF16<char16_t>>& elem, MemoryPoolAllocator<>& allocator);
    };


    class JsonObject : public JsonElem
    {
    public:
        JsonTuple   getMember(const UStr& name);

    protected:
        JsonObject(GenericValue<UTF16<char16_t>>& elem, MemoryPoolAllocator<>& allocator);
    };


    class JsonDoc : public JsonObject
    {
    private:
        GenericDocument<UTF16<char16_t>>  _doc;

    public:
        JsonDoc();

        UStr    toString();
    };
}
