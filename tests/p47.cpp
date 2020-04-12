#include "pch.h"

#include "../problems/p47.h"

TEST(p47, t0)
{
    p47::Solution s;

    std::vector<int> nums = {1, 1, 2};
    auto result = s.permuteUnique(nums);

    std::vector<std::vector<int>> expected = {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};

    EXPECT_EQ(result, expected);
}
