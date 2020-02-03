#pragma once


#include "JsonArray.hpp"
#include "JsonObject.hpp"


namespace StupidPoet
{
    class JsonDoc : public JsonObject
    {
    private:
        GenericDocument<UTF16<UChar>>  _doc;

    public:
        JsonDoc();
        // TODO: copy and assignment

        UStr        toString();
        inline void fromString(const UChar* str) { _doc.Parse(str); }

        inline MemoryPoolAllocator<>&   getAllocator() { return _doc.GetAllocator(); }
    };
}
