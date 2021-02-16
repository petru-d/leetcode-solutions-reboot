#include "pch.h"

#include "../problems/p1680.h"

TEST(p1680, t0)
{
    p1680::Solution s;

    auto res = s.concatenatedBinary(12);

    EXPECT_EQ(res, 505379714);
}
