#include "pch.h"

#include "../problems/p1713.h"

TEST(p1713, t0)
{
    p1713::Solution s;

    std::vector<int> target = {5, 1, 3};
    std::vector<int> arr = {9, 4, 2, 3, 4};

    auto res = s.minOperations(target, arr);

    EXPECT_EQ(res, 2);
}
