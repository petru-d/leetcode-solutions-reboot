#include "pch.h"

#include "../problems/p859.h"

TEST(p859, t0)
{
    p859::Solution s;

    auto res = s.buddyStrings("ab", "ba");

    EXPECT_TRUE(res);
}
