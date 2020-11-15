#include "pch.h"

#include "../problems/p458.h"

TEST(p458, t0)
{
    p458::Solution s;

    auto p = s.poorPigs(1000, 15, 60);

    EXPECT_EQ(p, 5);
}
