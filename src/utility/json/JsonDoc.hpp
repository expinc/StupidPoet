#pragma once


#include "JsonObject.hpp"


namespace StupidPoet
{
    class JsonDoc : public JsonObjectInterface
    {
    private:
        GenericDocument<UTF16<UChar>>  _doc;

    public:
        JsonDoc() { _doc.SetObject(); }

        inline JsonTuple   getMember(const UChar* name) override { return JsonTuple(name, _doc[name], _doc.GetAllocator()); }
        inline void    addMember(const UChar* name, bool value) override { addMember_T(name, value); }
        inline void    addMember(const UChar* name, int value) override { addMember_T(name, value); }
        inline void    addMember(const UChar* name, double value) override { addMember_T(name, value); }
        void    addMember(const UChar* name, const UChar* value) override;
        void    addMember(const UChar* name, const JsonValue& value) override;

        UStr    toString();

    private:
        template<typename type>
        void    addMember_T(const UChar* name, const type& value)
        {
            GenericStringRef<UChar> nameStr(name);
            _doc.AddMember(nameStr, value, _doc.GetAllocator());
        }
    };
}
