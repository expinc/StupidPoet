#pragma once


#include "JsonElem.hpp"


namespace StupidPoet
{
    class JsonArray : public JsonElem   // TODO
    {
    public:
        JsonElem    at(size_t index);

    protected:
        JsonArray(GenericValue<UTF16<char16_t>>& elem, MemoryPoolAllocator<>& allocator);
    };
}
