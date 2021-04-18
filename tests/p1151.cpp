#include "pch.h"

#include "../problems/p1151.h"

TEST(p1151, t0)
{
    p1151::Solution s;
    std::vector<int> data = {1, 0, 1, 0, 1};
    auto res = s.minSwaps(data);
    EXPECT_EQ(res, 1);
}
