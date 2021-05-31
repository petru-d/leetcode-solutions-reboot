#include "pch.h"

#include "../problems/p1167.h"

TEST(p1167, t0)
{
    std::vector<int> sticks = {2, 4, 3};
    p1167::Solution s;
    auto res = s.connectSticks(sticks);
    EXPECT_EQ(res, 14);
}
