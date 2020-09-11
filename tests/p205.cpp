#include "pch.h"

#include "../problems/p205.h"

TEST(p205, t0)
{
    p205::Solution s;

    auto res = s.isIsomorphic("abc", "def");

    EXPECT_TRUE(res);
}
