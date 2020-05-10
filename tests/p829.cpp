#include "pch.h"

#include "../problems/p829.h"

TEST(p829, t0)
{
    p829::Solution s;

    auto result = s.consecutiveNumbersSum(15);

    EXPECT_EQ(result, 4);
}
