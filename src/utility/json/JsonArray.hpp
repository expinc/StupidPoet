#pragma once


#include "JsonValue.hpp"


namespace StupidPoet
{
    class JsonArray : public JsonValue
    {
        friend class JsonValue;
        friend class JsonObject;

    public:
        inline JsonValue    at(size_t index) { return JsonValue(&_value[index], _allocator); }

        inline bool pushBack(const bool value) { return pushBack_T(value); }
        inline bool pushBack(const int value) { return pushBack_T(value); }
        inline bool pushBack(const double value) { return pushBack_T(value); }
        bool        pushBack(const UStr& value);
        bool        pushBack(const JsonValue& value);

        JsonArray& operator=(const JsonArray& other);

    protected:
        JsonArray(GenericValue<UTF16<UChar>>* value, MemoryPoolAllocator<>* allocator) :
            JsonValue(value, allocator)
        {}

    private:
        template<typename type>
        bool    pushBack_T(const type& value)
        {
            _value->PushBack(value, *_allocator);
            return true;
        }
    };
}
