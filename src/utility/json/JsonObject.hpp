#pragma once


#include "JsonArray.hpp"
#include "JsonObjectInterface.hpp"
#include "JsonTuple.hpp"


namespace StupidPoet
{
    class JsonObject : public JsonValue, public JsonObjectInterface
    {
    public:
        JsonTuple   getMember(const UChar* name) override;

        inline void addMemberValue(const UChar* name, bool value) override { addMemberValue_T<bool>(name, value); }
        inline void addMemberValue(const UChar* name, int value) override { addMemberValue_T<int>(name, value); }
        inline void addMemberValue(const UChar* name, double value) override { addMemberValue_T<double>(name, value); }
        void        addMemberValue(const UChar* name, const UChar* value) override;
        JsonArray   addMemberArray(const UChar* name) override;
        JsonObject  addMemberObject(const UChar* name) override;
        void        addMemberNull(const UChar* name) override;

    protected:
        JsonObject(GenericValue<UTF16<UChar>>* value, MemoryPoolAllocator<>* allocator) :
            JsonValue(value, allocator)
        {}

    private:
        template<typename type>
        void    addMemberValue_T(const UChar* name, const type& value)
        {
            GenericStringRef<UChar> nameStr(name);
            _value->AddMember(nameStr, value, *_allocator);
        }

        friend class JsonValue;
    };
}
