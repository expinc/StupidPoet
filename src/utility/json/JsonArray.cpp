#include "JsonArray.hpp"


namespace StupidPoet
{
    bool JsonArray::pushBack(const bool value)
    {
        if (_elemType != ValueType::Bool)
            return false;

        _value.PushBack(value, _allocator);
        return true;
    }


    bool JsonArray::pushBack(const int value)
    {
        if (_elemType != ValueType::Int)
            return false;

        _value.PushBack(value, _allocator);
        return true;
    }


    bool JsonArray::pushBack(const double value)
    {
        if (_elemType != ValueType::Double)
            return false;

        _value.PushBack(value, _allocator);
        return true;
    }


    bool JsonArray::pushBack(const UStr& value)
    {
        if (_elemType != ValueType::Str)
            return false;

        GenericStringRef<UChar> str(value.c_str());
        _value.PushBack(str, _allocator);
        return true;
    }


    bool JsonArray::pushBack(const JsonValue& value)
    {
        if (_elemType != value.getValueType(value._value))
            return false;

        _value.PushBack(value._value, _allocator);
        return true;
    }
}
