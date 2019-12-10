#include "JsonDoc.hpp"


namespace StupidPoet
{
    void JsonDoc::addMember(const UChar* name, const UChar* value)
    {
        GenericStringRef<UChar> valueStr(value);
        this->addMember_T(name, valueStr);
    }


    void JsonDoc::addMember(const UChar* name, const JsonValue& value)
    {
        GenericStringRef<UChar> nameStr(name);
        _doc.AddMember(nameStr, value._value, _doc.GetAllocator());
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
