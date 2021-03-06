#include "JsonArray.hpp"
#include "JsonObject.hpp"


namespace StupidPoet
{

    bool JsonArray::pushBack(const UStr& value)
    {
        GenericValue<UTF16<UChar>>  valueStr(value.c_str(), *_allocator);
        _value->PushBack(valueStr, *_allocator);
        return true;
    }


    bool JsonArray::pushBack(const JsonValue& value)
    {
        _value->PushBack(*(value._value), *_allocator);
        return true;
    }


    JsonObject JsonArray::appendObject()
    {
        GenericValue<UTF16<char16_t>> object(rapidjson::kObjectType);
        _value->PushBack(object, *_allocator);
        auto    last = &((*_value)[_value->Size() - 1]);
        return JsonObject(last, _allocator);
    }
}
