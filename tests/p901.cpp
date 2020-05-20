#include "pch.h"

#include "../problems/p901.h"

TEST(p901, t0)
{
    p901::StockSpanner s;

    auto res = s.next(100);
    EXPECT_EQ(res, 1);

    res = s.next(80);
    EXPECT_EQ(res, 1);

    res = s.next(60);
    EXPECT_EQ(res, 1);

    res = s.next(70);
    EXPECT_EQ(res, 2);

    res = s.next(60);
    EXPECT_EQ(res, 1);

    res = s.next(75);
    EXPECT_EQ(res, 4);

    res = s.next(85);
    EXPECT_EQ(res, 6);
}

TEST(p901, t1)
{
    p901::StockSpanner s;

    auto res = s.next(28);
    EXPECT_EQ(res, 1);

    res = s.next(14);
    EXPECT_EQ(res, 1);

    res = s.next(28);
    EXPECT_EQ(res, 3);
}

TEST(p901, t2)
{
    p901::StockSpanner s;

    auto res = s.next(28);
    EXPECT_EQ(res, 1);

    res = s.next(14);
    EXPECT_EQ(res, 1);

    res = s.next(28);
    EXPECT_EQ(res, 3);

    res = s.next(35);
    EXPECT_EQ(res, 4);

    res = s.next(46);
    EXPECT_EQ(res, 5);

    res = s.next(53);
    EXPECT_EQ(res, 6);
}

TEST(p901, t3)
{
    p901::StockSpanner s;

    auto res = s.next(52);
    EXPECT_EQ(res, 1);

    res = s.next(49);
    EXPECT_EQ(res, 1);

    res = s.next(78);
    EXPECT_EQ(res, 3);

    res = s.next(43);
    EXPECT_EQ(res, 1);

    res = s.next(68);
    EXPECT_EQ(res, 2);

    res = s.next(27);
    EXPECT_EQ(res, 1);

    res = s.next(37);
    EXPECT_EQ(res, 2);
}
