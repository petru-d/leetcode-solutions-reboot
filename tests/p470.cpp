#include "pch.h"

#include "../problems/p470.h"

TEST(p470, t0)
{
    p470::Solution s;
    auto r = s.rand10();

    EXPECT_TRUE(1 <= r && r <= 10);
}
