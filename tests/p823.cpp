#include "pch.h"

#include "../problems/p823.h"

TEST(p823, t0)
{
    p823::Solution s;

    std::vector<int> nums = {2, 4, 5, 10};
    auto res = s.numFactoredBinaryTrees(nums);
    EXPECT_EQ(res, 7);
}
