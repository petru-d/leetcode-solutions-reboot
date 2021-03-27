#include "pch.h"

#include "../problems/p647.h"

TEST(p647, t0)
{
    p647::Solution s;
    auto res = s.countSubstrings("axxa");
    EXPECT_EQ(res, 6);
}
