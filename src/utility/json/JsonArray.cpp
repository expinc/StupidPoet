#include "JsonArray.hpp"


namespace StupidPoet
{

    bool JsonArray::pushBack(const UStr& value)
    {
        GenericStringRef<UChar> str(value.c_str());
        _value->PushBack(str, *_allocator);
        return true;
    }


    bool JsonArray::pushBack(const JsonValue& value)
    {
        _value->PushBack(*(value._value), *_allocator);
        return true;
    }
}
