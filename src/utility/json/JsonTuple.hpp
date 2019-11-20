#pragma once


#include "JsonElem.hpp"


namespace StupidPoet
{
    class JsonTuple : public JsonElem   // TODO
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
}
