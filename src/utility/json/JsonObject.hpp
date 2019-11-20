#pragma once


#include "JsonTuple.hpp"


namespace StupidPoet
{
    class JsonObject : public JsonElem  // TODO
    {
    public:
        JsonTuple   getMember(const UStr& name);

    protected:
        JsonObject(GenericValue<UTF16<char16_t>>& elem, MemoryPoolAllocator<>& allocator);
    };
}
