#include "pch.h"

#include "../problems/p1240.h"

TEST(p1240, t0)
{
    p1240::Solution s;

    auto res = s.tilingRectangle(2, 3);

    EXPECT_EQ(res, 3);
}

TEST(p1240, t1)
{
    p1240::Solution s;

    auto res = s.tilingRectangle(5, 8);

    EXPECT_EQ(res, 5);
}

TEST(p1240, t2)
{
    p1240::Solution s;

    auto res = s.tilingRectangle(11, 13);

    EXPECT_EQ(res, 6);
}

TEST(p1240, t3)
{
    p1240::Solution s;

    auto res = s.tilingRectangle(8, 1);

    EXPECT_EQ(res, 8);
}
