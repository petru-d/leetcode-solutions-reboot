#include "pch.h"

#include "../problems/p1528.h"

TEST(p1528, t0)
{
    p1528::Solution s;

    std::vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};

    auto res = s.restoreString("codeleet", indices);

    EXPECT_EQ(res, "leetcode");
}

TEST(p1528, t1)
{
    p1528::Solution s;

    std::vector<int> indices = {0, 1, 2};

    auto res = s.restoreString("abc", indices);

    EXPECT_EQ(res, "abc");
}

TEST(p1528, t2)
{
    p1528::Solution s;

    std::vector<int> indices = {3, 1, 4, 2, 0};

    auto res = s.restoreString("aiohn", indices);

    EXPECT_EQ(res, "nihao");
}

TEST(p1528, t3)
{
    p1528::Solution s;

    std::vector<int> indices = {4, 0, 2, 6, 7, 3, 1, 5};

    auto res = s.restoreString("aaiougrt", indices);

    EXPECT_EQ(res, "arigatou");
}

TEST(p1528, t4)
{
    p1528::Solution s;

    std::vector<int> indices = {1, 0, 2};

    auto res = s.restoreString("art", indices);

    EXPECT_EQ(res, "rat");
}
