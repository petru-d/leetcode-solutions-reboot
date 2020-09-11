#include "pch.h"

#include "../problems/p165.h"

TEST(p165, t0)
{
    p165::Solution s;

    auto res = s.compareVersion("1", "1");

    EXPECT_EQ(res, 0);
}
