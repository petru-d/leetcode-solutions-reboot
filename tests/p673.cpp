#include "pch.h"

#include "../problems/p673.h"

TEST(p673, t0)
{
    p673::Solution s;

    std::vector<int> n = {1, 3, 5, 4, 7};
    auto res = s.findNumberOfLIS(n);

    EXPECT_EQ(res, 2);
}
