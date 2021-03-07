#include "pch.h"

#include "../problems/p575.h"

TEST(p575, t0)
{
    p575::Solution s;
    std::vector<int> candyType = {1, 1, 2, 2, 3, 3};
    auto res = s.distributeCandies(candyType);
    EXPECT_EQ(res, 3);
}
