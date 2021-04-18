#include "pch.h"

#include "../problems/p509.h"

TEST(p509, t0)
{
    p509::Solution s;
    auto res = s.fib(3);
    EXPECT_EQ(res, 2);
}
