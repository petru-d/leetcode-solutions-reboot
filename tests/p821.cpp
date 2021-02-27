#include "pch.h"

#include "../problems/p821.h"

TEST(p821, t0)
{
    p821::Solution s;

    auto res = s.shortestToChar("aaab", 'b');

    EXPECT_EQ(res, (std::vector<int>{3, 2, 1, 0}));
}
