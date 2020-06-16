#include "pch.h"

#include "../problems/p371.h"

TEST(p371, t0)
{
    p371::Solution s;
    auto res = s.getSum(2, 3);
    EXPECT_EQ(res, 5);
}
