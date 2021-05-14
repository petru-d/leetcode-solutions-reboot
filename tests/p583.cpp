#include "pch.h"

#include "../problems/p583.h"

TEST(p583, t0)
{
    p583::Solution s;
    auto res = s.minDistance("sea", "eat");
    EXPECT_EQ(res, 2);
}
