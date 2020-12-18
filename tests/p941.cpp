#include "pch.h"

#include "../problems/p941.h"

TEST(p941, t0)
{
    p941::Solution s;
    std::vector<int> arr = {2, 1};
    auto res = s.validMountainArray(arr);

    EXPECT_FALSE(res);
}
