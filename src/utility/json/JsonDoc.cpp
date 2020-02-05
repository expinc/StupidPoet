#include "JsonDoc.hpp"


namespace StupidPoet
{
    JsonDoc::JsonDoc() :
        JsonObject(nullptr, nullptr)
    {
        _doc.SetObject();
        _value = &_doc;
        _allocator = &_doc.GetAllocator();
    }


    JsonDoc& JsonDoc::operator=(const JsonDoc& other)
    {
        _doc.CopyFrom(other._doc, _doc.GetAllocator());
        _value = &_doc;
        _allocator = &_doc.GetAllocator();
        return *this;
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
