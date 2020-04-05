#include "pch.h"

#include "../problems/p47.h"

TEST(P47, T0)
{
    p47::Solution s;

    std::vector<int> nums = {1, 1, 2};
    auto result = s.permuteUnique(nums);

    std::vector<std::vector<int>> expected = {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};

    EXPECT_EQ(result, expected);
}
