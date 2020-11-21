#include "pch.h"

#include "../problems/p845.h"

TEST(p845, t0)
{
    p845::Solution s;

    std::vector<int> arr = {2, 1, 4, 7, 3, 2, 5};
    auto res = s.longestMountain(arr);

    EXPECT_EQ(res, 5);
}
