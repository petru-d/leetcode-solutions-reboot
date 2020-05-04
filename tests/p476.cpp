#include "pch.h"

#include "../problems/p476.h"

TEST(p476, t0)
{
    p476::Solution s;
    auto res = s.findComplement(5);
    EXPECT_EQ(res, 2);
}
