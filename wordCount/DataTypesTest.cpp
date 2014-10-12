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

TEST(DataTypesTest, ForceCollision)
{
    HashMap map = HashMap(1);
    map.setValue("dfhcofsiuy");
    map.setValue("dfh");
    ASSERT_EQ(1, map.getValue("dfhcofsiuy"));
    ASSERT_EQ(1, map.getValue("dfh"));
}

TEST(DataTypesTest, SortMap)
{
    HashMap map = HashMap(3);
    MostRepeatedWord words[2];
    
    for (int i = 0; i < 20; i++)
    {
        map.setValue("dfhcofsiuy");
        if (i % 4 == 0) map.setValue("dff");
        if (i % 2 == 0) map.setValue("dfhcof");
    }
    map.sortHash(2, words);
    ASSERT_EQ("dfhcofsiuy", words[0].word);
    ASSERT_EQ(20, words[0].occurance);
    ASSERT_EQ("dfhcof", words[1].word);
    ASSERT_EQ(10, words[1].occurance);
    ASSERT_EQ("dff", words[2].word);
    ASSERT_EQ(5, words[2].occurance);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
