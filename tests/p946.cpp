#include "pch.h"

#include "../problems/p946.h"

TEST(p946, t0)
{
    p946::Solution s;

    std::vector<int> pushed = {1, 2, 3, 4, 5};
    std::vector<int> popped = {4, 5, 3, 2, 1};

    auto res = s.validateStackSequences(pushed, popped);
    EXPECT_TRUE(res);
}
