#include <gtest/gtest.h>
#include "utility/json/JsonDoc.hpp"


using namespace testing;


namespace StupidPoet
{
    TEST(TestJsonDoc, General)
    {
        JsonDoc doc;
    }
}


int main(int argc, char* argv[])
{
    InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
