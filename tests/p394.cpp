#include "pch.h"

#include "../problems/p394.h"

TEST(p394, t0)
{
    p394::Solution s;

    auto res = s.decodeString("3[a2[c]]");

    EXPECT_EQ(res, "accaccacc");
}
