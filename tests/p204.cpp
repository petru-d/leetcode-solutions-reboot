#include "pch.h"

#include "../problems/p204.h"

TEST(p204, t0)
{
    p204::Solution s;
    auto res = s.countPrimes(10);
    EXPECT_EQ(res, 4);

    p204::Solution2 s2;
    res = s2.countPrimes(10);
    EXPECT_EQ(res, 4);
}
