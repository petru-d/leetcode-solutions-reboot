#include "pch.h"

#include "../problems/p338.h"

TEST(p338, t0)
{
    p338::Solution s;
    auto res = s.countBits(5);

    std::vector<int> expected = {0, 1, 1, 2, 1, 2};
    EXPECT_EQ(res, expected);
}