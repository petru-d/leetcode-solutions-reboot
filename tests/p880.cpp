#include "pch.h"

#include "../problems/p880.h"

TEST(p880, t0)
{
    p880::Solution s;
    auto res = s.decodeAtIndex("leet2code3", 10);
    EXPECT_EQ(res, "o");
}
