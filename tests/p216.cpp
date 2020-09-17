#include "pch.h"

#include "../problems/p216.h"

TEST(p216, t0)
{
    p216::Solution s;

    auto res = s.combinationSum3(3, 9);

    std::vector<std::vector<int>> expected = {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}};
    EXPECT_EQ(res, expected);
}

TEST(p216, t1)
{
    p216::Solution s;

    auto res = s.combinationSum3(3, 7);

    std::vector<std::vector<int>> expected = {{1, 2, 4}};
    EXPECT_EQ(res, expected);
}

TEST(p216, t2)
{
    p216::Solution s;

    auto res = s.combinationSum3(2, 18);

    std::vector<std::vector<int>> expected = {};
    EXPECT_EQ(res, expected);
}
