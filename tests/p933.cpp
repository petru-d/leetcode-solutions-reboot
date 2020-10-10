#include "pch.h"

#include "../problems/p933.h"

TEST(p933, t0)
{
    p933::RecentCounter s;
    auto res = s.ping(1);

    EXPECT_EQ(res, 1);
}
