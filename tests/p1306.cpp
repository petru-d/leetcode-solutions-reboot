#include "pch.h"

#include "../problems/p1306.h"

TEST(p1306, t0)
{
    p1306::Solution s;

    std::vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
    auto res = s.canReach(arr, 5);

    EXPECT_TRUE(res);
}
