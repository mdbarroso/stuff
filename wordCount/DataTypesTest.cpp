#include <gtest/gtest.h>
#include "DataTypes.cpp"

TEST(DataTypesTest, SetNGet)
{
    HashMap map = HashMap(5);
    map.setValue("dfhcofsiuy");
    ASSERT_EQ(1, map.getValue("dfhcofsiuy"));
}

TEST(DataTypesTest, InexistentElement)
{
    HashMap map = HashMap(5);
    map.setValue("dfhcofsiuy");
    ASSERT_EQ(0, map.getValue("dfhco"));
}

TEST(DataTypesTest, RepeatedElement)
{
    HashMap map = HashMap(5);
    map.setValue("dfhcofsiuy");
    map.setValue("dfhcofsiuy");
    ASSERT_EQ(2, map.getValue("dfhcofsiuy"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
