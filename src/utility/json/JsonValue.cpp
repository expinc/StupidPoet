#include "JsonValue.hpp"

#include "JsonArray.hpp"
#include "JsonObject.hpp"
#include "utility\UtilityException.hpp"


namespace StupidPoet
{
    #define JSON_ERROR_WRONG_TYPE   u"Wrong json value type!"


    JsonValue::JsonValue(GenericValue<UTF16<UChar>>* value, MemoryPoolAllocator<>* allocator) :
        _value(value),
        _allocator(allocator)
    {
        if (this->isValid())
            _valueType = getValueType(*value);
        else
            _valueType = ValueType::Null;
    }


    JsonValue::ValueType JsonValue::getValueType(const GenericValue<UTF16<UChar>>& rapidValue)
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


    bool JsonValue::getBool() const
    {
        if (ValueType::Bool != _valueType)
            throw UtilityException(JSON_ERROR_WRONG_TYPE);

        return _value->GetBool();
    }


    int JsonValue::getInt() const
    {
        if (ValueType::Int != _valueType)
            throw UtilityException(JSON_ERROR_WRONG_TYPE);

        return _value->GetInt();
    }


    double JsonValue::getDouble() const
    {
        if (ValueType::Double != _valueType)
            throw UtilityException(JSON_ERROR_WRONG_TYPE);

        return _value->GetDouble();
    }


    UStr JsonValue::getStr() const
    {
        if (ValueType::Str != _valueType)
            throw UtilityException(JSON_ERROR_WRONG_TYPE);

        return _value->GetString();
    }


    JsonArray JsonValue::getArray() const
    {
        if (ValueType::Array != _valueType)
            throw UtilityException(JSON_ERROR_WRONG_TYPE);

        return JsonArray(_value, _allocator);
    }


    JsonObject JsonValue::getObject() const
    {
        if (ValueType::Object != _valueType)
            throw UtilityException(JSON_ERROR_WRONG_TYPE);

        return JsonObject(_value, _allocator);
    }
}
