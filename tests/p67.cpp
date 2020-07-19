#include "pch.h"

#include "../problems/p67.h"

TEST(p67, t0)
{
    p67::Solution s;
    auto res = s.addBinary("11", "1");
    EXPECT_EQ(res, "100");
}
