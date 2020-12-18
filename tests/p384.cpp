#include "pch.h"

#include "../problems/p384.h"

#include <algorithm>

TEST(p384, t0)
{
    std::vector<int> nums = {1, 2, 3};
    p384::Solution s(nums);

    auto res = s.shuffle();
    EXPECT_TRUE(std::is_permutation(nums.begin(), nums.end(), res.begin(), res.end()));
}
