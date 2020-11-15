#include "pch.h"

#include "../problems/p1290.h"

TEST(p1290, t0)
{
    p1290::Solution s;
    auto res = s.getDecimalValue(make_list({1, 0, 1}));

    EXPECT_EQ(res, 5);
}
