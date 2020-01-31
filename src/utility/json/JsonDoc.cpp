#include "JsonDoc.hpp"


namespace StupidPoet
{
    JsonDoc::JsonDoc() :
        JsonObject(&_doc, &_doc.GetAllocator())
    {
        _doc.SetObject();
        _allocator = &_doc.GetAllocator();
    }


    UStr JsonDoc::toString()
    {
        GenericStringBuffer<UTF16<UChar>> buffer;
        Writer<GenericStringBuffer<UTF16<UChar>>, UTF16<UChar>, UTF16<UChar>> writer(buffer);
        _doc.Accept(writer);
        UStr result(buffer.GetString());
        return std::move(result);
    }
}
