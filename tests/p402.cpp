#include "pch.h"

#include "../problems/p402.h"

TEST(p402, t0)
{
    p402::Solution s;
    auto result = s.removeKdigits("1432219", 3);

    EXPECT_EQ(result, "1219");
}

TEST(p402, t1)
{
    p402::Solution s;
    auto result = s.removeKdigits("10200", 1);

    EXPECT_EQ(result, "200");
}

TEST(p402, t2)
{
    p402::Solution s;
    auto result = s.removeKdigits("10", 2);

    EXPECT_EQ(result, "0");
}

TEST(p402, t3)
{
    p402::Solution s;
    auto result = s.removeKdigits("112", 1);

    EXPECT_EQ(result, "11");
}

TEST(p402, t4)
{
    p402::Solution s;
    auto result = s.removeKdigits("1107", 1);

    EXPECT_EQ(result, "107");
}

TEST(p402, t5)
{
    p402::Solution s;
    auto result = s.removeKdigits("1234567890", 9);

    EXPECT_EQ(result, "0");
}
