#include "JsonObject.hpp"
#include "utility\UtilityException.hpp"


namespace StupidPoet
{
    JsonTuple JsonObject::getMember(const UChar* name)
    {
        if (!_value->HasMember(name))
            throw UtilityException(u"No such member in json!");

        return JsonTuple(name, &((*_value)[name]), _allocator);
    }


    void JsonObject::addMemberValue(const UChar* name, const UChar* value)
    {
        GenericValue<UTF16<UChar>>  nameStr(name, *_allocator);
        GenericValue<UTF16<UChar>>  valueStr(value, *_allocator);
        _value->AddMember(nameStr, valueStr, *_allocator);
    }


    JsonArray JsonObject::addMemberArray(const UChar* name)
    {
        GenericValue<UTF16<UChar>>  nameStr(name, *_allocator);
        _value->AddMember(nameStr, GenericValue<UTF16<char16_t>>(Type::kArrayType), *_allocator);
        JsonArray   array(&(*_value)[name], _allocator);
        return array;
    }


    JsonObject JsonObject::addMemberObject(const UChar* name)
    {
        GenericValue<UTF16<UChar>>  nameStr(name, *_allocator);
        _value->AddMember(nameStr, GenericValue<UTF16<char16_t>>(Type::kObjectType), *_allocator);
        JsonObject  object(&(*_value)[name], _allocator);
        return object;
    }


    void JsonObject::addMemberNull(const UChar* name)
    {
        GenericValue<UTF16<UChar>>  nameStr(name, *_allocator);
        _value->AddMember(nameStr, GenericValue<rapidjson::UTF16<char16_t>>().Move(), *_allocator);
    }
}
