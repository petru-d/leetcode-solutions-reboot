#include "pch.h"

#include "../problems/p696.h"

TEST(p696, t0)
{
    p696::Solution s;
    auto res = s.countBinarySubstrings("00110011");
    EXPECT_EQ(res, 6);
}
