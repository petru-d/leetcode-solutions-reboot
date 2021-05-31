#include "pch.h"

#include "../problems/p1689.h"

TEST(p1689, t0)
{
    p1689::Solution s;
    auto res = s.minPartitions("32");
    EXPECT_EQ(res, 3);

    p1689::Solution2 s2;
    auto res2 = s2.minPartitions("32");
    EXPECT_EQ(res2, 3);
}
