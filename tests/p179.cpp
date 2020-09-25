#include "pch.h"

#include "../problems/p179.h"

TEST(p179, t0_)
{
    p179::Solution s;

    std::vector<int> nums = {121, 12};

    auto x = s.lessstr("121", "12");
    EXPECT_TRUE(x);

    x = s.lessstr("12", "121");
    EXPECT_FALSE(x);

    x = s.lessstr("128", "12");
    EXPECT_FALSE(x);
    x = s.lessstr("12", "128");
    EXPECT_TRUE(x);

    x = s.lessstr("12", "1212");
    EXPECT_TRUE(x);

    x = s.lessstr("1212", "12");
    EXPECT_FALSE(x);

    x = s.lessstr("3", "30");
    EXPECT_FALSE(x);

    x = s.lessstr("30", "3");
    EXPECT_TRUE(x);

    x = s.lessstr("3", "34");
    EXPECT_TRUE(x);

    x = s.lessstr("34", "3");
    EXPECT_FALSE(x);
}

TEST(p179, t0)
{
    p179::Solution s;

    std::vector<int> nums = {121, 12};

    auto res = s.largestNumber(nums);
    EXPECT_EQ(res, "12121");
}

TEST(p179, t1)
{
    p179::Solution s;

    std::vector<int> nums = {128, 12};
    auto res = s.largestNumber(nums);

    EXPECT_EQ(res, "12812");
}

TEST(p179, t2)
{
    p179::Solution s;

    std::vector<int> nums = {0, 0};
    auto res = s.largestNumber(nums);

    EXPECT_EQ(res, "0");
}
