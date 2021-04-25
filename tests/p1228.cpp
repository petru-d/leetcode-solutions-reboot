#include "pch.h"

#include "../problems/p1228.h"

TEST(p1228, t0)
{
    std::vector<int> arr = {1, 2, 4};
    p1228::Solution s;
    auto res = s.missingNumber(arr);
    EXPECT_EQ(res, 3);
}
