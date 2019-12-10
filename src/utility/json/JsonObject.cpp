#include "JsonObject.hpp"

#include "utility\UtilityException.hpp"


namespace StupidPoet
{
    JsonTuple JsonObject::getMember(const UChar* name)
    {
        if (!_value.HasMember(name))
            throw UtilityException(u"No such member in json!");

        return JsonTuple(name, _value[name], _allocator);
    }


    void JsonObject::addMember(const UChar* name, const UChar* value)
    {
        GenericStringRef<UChar> valueStr(value);
        this->addMember_T(name, valueStr);
    }


    void JsonObject::addMember(const UChar* name, const JsonValue& value)
    {
        GenericStringRef<UChar> nameStr(name);
        _value.AddMember(nameStr, value._value, _allocator);
    }
}
