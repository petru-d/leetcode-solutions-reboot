#include "pch.h"

#include "../problems/p566.h"

TEST(p566, t0)
{
    p566::Solution s;

    std::vector<std::vector<int>> nums = {{1, 2}, {3, 4}};
    auto res = s.matrixReshape(nums, 1, 4);
    std::vector<std::vector<int>> expected = {{1, 2, 3, 4}};

    EXPECT_EQ(res, expected);
}
