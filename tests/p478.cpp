#include "pch.h"

#include "../problems/p478.h"

TEST(p478, t0)
{
    p478::Solution s(10, 0, 0);

    auto res = s.randPoint();

    ASSERT_TRUE(res.size() == 2);
    EXPECT_TRUE(res[0] * res[0] + res[1] * res[1] <= 100);
}
