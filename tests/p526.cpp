#include "pch.h"

#include "../problems/p526.h"

TEST(p526, t0)
{
    p526::Solution s;

    auto res = s.countArrangement(1);

    EXPECT_EQ(res, 1);
}
