#include "pch.h"

#include "../problems/p278.h"

TEST(p278, t0)
{
    p278::Solution s;

    s.set_bad_version(4);

    auto res = s.firstBadVersion(5);

    EXPECT_EQ(res, 4);
}

TEST(p278, t1)
{
    p278::Solution s;

    s.set_bad_version(1);

    auto res = s.firstBadVersion(5);

    EXPECT_EQ(res, 1);
}