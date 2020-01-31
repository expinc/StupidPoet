#include <gtest/gtest.h>
#include "utility/json/JsonDoc.hpp"


using namespace testing;


namespace StupidPoet
{
    static UChar*   s_jsonGeneral = u"{\"fuck\":true,\"shit\":[1,2,3],\"butt\":{\"suck\":\"锤子\"},\"nothing\":null}";


    TEST(TestJsonDoc, writeToString)
    {
        JsonDoc doc;

        doc.addMemberValue(u"fuck", true);

        auto    shit = doc.addMemberArray(u"shit");
        shit.pushBack(1);
        shit.pushBack(2);
        shit.pushBack(3);

        auto    butt = doc.addMemberObject(u"butt");
        butt.addMemberValue(u"suck", u"锤子");

        doc.addMemberNull(u"nothing");

        EXPECT_EQ(s_jsonGeneral, doc.toString());
    }
}
