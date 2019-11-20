#pragma once


#include "JsonObject.hpp"


namespace StupidPoet
{
    class JsonDoc : public JsonObject   // TODO
    {
    private:
        GenericDocument<UTF16<char16_t>>  _doc;

    public:
        JsonDoc();

        UStr    toString();
    };
}
