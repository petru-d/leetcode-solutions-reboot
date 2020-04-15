#include "pch.h"

#include "../problems/p238.h"

TEST(p238, t0)
{
    p238::Solution s;

    std::vector<int> nums = {3, 7, 5, 2};
    auto result = s.productExceptSelf(nums);
    std::vector<int> expected = {70, 30, 42, 105};
    EXPECT_EQ(result, expected);
}
