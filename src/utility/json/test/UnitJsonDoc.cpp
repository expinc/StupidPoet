#include <gtest/gtest.h>
#include <memory>
#include "utility/json/JsonDoc.hpp"


using namespace testing;


namespace StupidPoet
{
    static UChar*   s_jsonOrdinary = u"{\"fuck\":true,\"shit\":[1,2,3],\"butt\":{\"suck\":\"锤子\"},\"nothing\":null}";


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

        EXPECT_EQ(s_jsonOrdinary, doc.toString());
    }


    TEST(TestJsonDoc, readFromString)
    {
        // Ordinary string
        JsonDoc doc;
        doc.fromString(s_jsonOrdinary);
        ASSERT_EQ(s_jsonOrdinary, doc.toString());

        ASSERT_TRUE(doc.hasMember(u"fuck"));
        EXPECT_TRUE(doc.getMember(u"fuck").getBool());
        EXPECT_FALSE(doc.getMember(u"fuck").isNull());

        ASSERT_TRUE(doc.hasMember(u"shit"));
        auto    shit = doc.getMember(u"shit").getArray();
        EXPECT_EQ(3u, shit.size());
        EXPECT_EQ(1, shit.at(0).getInt());
        EXPECT_EQ(2, shit.at(1).getInt());
        EXPECT_EQ(3, shit.at(2).getInt());

        ASSERT_TRUE(doc.hasMember(u"butt"));
        auto    butt = doc.getMember(u"butt").getObject();
        ASSERT_TRUE(butt.hasMember(u"suck"));
        EXPECT_EQ(u"锤子", butt.getMember(u"suck").getStr());

        ASSERT_TRUE(doc.hasMember(u"nothing"));
        EXPECT_TRUE(doc.getMember(u"nothing").isNull());

        // Invalid string
        JsonDoc invalidDoc;
        invalidDoc.fromString(u"xxx");
        ASSERT_EQ(u"{}", invalidDoc.toString());

        // Empty json
        JsonDoc emptyDoc;
        emptyDoc.fromString(u"{}");
        ASSERT_EQ(u"{}", emptyDoc.toString());
    }


    TEST(TestJsonDoc, copyAndAssign)
    {
        auto    originDoc = std::make_unique<JsonDoc>();
        originDoc->fromString(s_jsonOrdinary);

        JsonDoc copiedDoc(*originDoc);
        JsonDoc assignedDoc = *originDoc;

        originDoc.reset();
        EXPECT_EQ(s_jsonOrdinary, copiedDoc.toString());
        EXPECT_EQ(s_jsonOrdinary, assignedDoc.toString());
    }
}
