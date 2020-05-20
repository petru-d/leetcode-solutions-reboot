#include "pch.h"

#include "../problems/p567.h"

TEST(p567, t0)
{
    p567::Solution s;
    auto res = s.checkInclusion("ab", "eidbaooo");
    EXPECT_EQ(res, true);
}

TEST(p567, t1)
{
    p567::Solution s;
    auto res = s.checkInclusion("ab", "eidboaoo");
    EXPECT_EQ(res, false);
}

TEST(p567, t2)
{
    p567::Solution s;
    auto res = s.checkInclusion("a", "ab");
    EXPECT_EQ(res, true);
}
