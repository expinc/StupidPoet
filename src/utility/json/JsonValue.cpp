#include "JsonValue.hpp"

#include "JsonArray.hpp"
#include "JsonObject.hpp"
#include "utility\UtilityException.hpp"


namespace StupidPoet
{
    JsonValue::ValueType JsonValue::getValueType(const GenericValue<UTF16<char16_t>>& rapidValue)
    {
        switch (rapidValue.GetType())
        {
        case Type::kNullType:
            return ValueType::Null;
            break;

        case Type::kTrueType:
        case Type::kFalseType:
            return ValueType::Bool;
            break;

        case Type::kNumberType:
            if (rapidValue.IsInt())
                return ValueType::Int;
            else
                return ValueType::Double;
            break;

        case Type::kStringType:
            return ValueType::Str;
            break;

        case Type::kArrayType:
            return ValueType::Array;
            break;

        case Type::kObjectType:
            return ValueType::Object;
            break;

        default:
            return ValueType::Null;
            break;
        }
    }


    bool JsonValue::getBool()
    {
        if (ValueType::Bool != _valueType)
            throw UtilityException(u"Wrong json value type!");

        return _value.GetBool();
    }


    int JsonValue::getInt()
    {
        if (ValueType::Int != _valueType)
            throw UtilityException(u"Wrong json value type!");

        return _value.GetInt();
    }


    double JsonValue::getDouble()
    {
        if (ValueType::Double != _valueType)
            throw UtilityException(u"Wrong json value type!");

        return _value.GetDouble();
    }


    UStr JsonValue::getStr()
    {
        if (ValueType::Str != _valueType)
            throw UtilityException(u"Wrong json value type!");

        return _value.GetString();
    }


    JsonArray JsonValue::getArray()
    {
        if (ValueType::Array != _valueType)
            throw UtilityException(u"Wrong json value type!");

        return JsonArray(_value, _allocator);
    }


    JsonObject JsonValue::getObject()
    {
        if (ValueType::Object != _valueType)
            throw UtilityException(u"Wrong json value type!");

        return JsonObject(_value, _allocator);
    }
}
