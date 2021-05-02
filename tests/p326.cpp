#include "pch.h"

#include "../problems/p326.h"

TEST(p326, t0)
{
    p326::Solution s;
    auto res = s.isPowerOfThree(3);
    EXPECT_TRUE(res);

    p326::Solution2 s2;
    res = s2.isPowerOfThree(3);
    EXPECT_TRUE(res);
}
