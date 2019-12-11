#pragma once


#include "JsonObjectInterface.hpp"
#include "JsonTuple.hpp"


namespace StupidPoet
{
    class JsonObject : public JsonValue, public JsonObjectInterface
    {
    public:
        JsonTuple   getMember(const UChar* name) override;
        inline void    addMember(const UChar* name, bool value) override { addMember_T(name, value); }
        inline void    addMember(const UChar* name, int value) override { addMember_T(name, value); }
        inline void    addMember(const UChar* name, double value) override { addMember_T(name, value); }
        void    addMember(const UChar* name, const UChar* value) override;
        void    addMember(const UChar* name, const JsonValue& value) override;

    protected:
        JsonObject(GenericValue<UTF16<UChar>>& value, MemoryPoolAllocator<>& allocator) :
            JsonValue(value, allocator)
        {}

    private:
        template<typename type>
        void    addMember_T(const UChar* name, const type& value)
        {
            GenericStringRef<UChar> nameStr(name);
            _value.AddMember(nameStr, value, _allocator);
        }

        friend class JsonValue;
    };
}
