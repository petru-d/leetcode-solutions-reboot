#include "pch.h"

#include "../problems/p732.h"

TEST(p732, t0)
{
    p732::MyCalendarThree c;

    auto res = c.book(10, 20);
    EXPECT_EQ(res, 1);

    res = c.book(50, 60);
    EXPECT_EQ(res, 1);

    res = c.book(10, 40);
    EXPECT_EQ(res, 2);

    res = c.book(5, 15);
    EXPECT_EQ(res, 3);

    res = c.book(5, 10);
    EXPECT_EQ(res, 3);

    res = c.book(25, 55);
    EXPECT_EQ(res, 3);
}

TEST(p732, t1)
{
    p732::MyCalendarThree c;

    auto res = c.book(26, 35);
    EXPECT_EQ(res, 1);

    res = c.book(26, 32);
    EXPECT_EQ(res, 2);

    res = c.book(25, 32);
    EXPECT_EQ(res, 3);

    res = c.book(18, 26);
    EXPECT_EQ(res, 3);

    res = c.book(40, 45);
    EXPECT_EQ(res, 3);

    res = c.book(19, 26);
    EXPECT_EQ(res, 3);

    res = c.book(48, 50);
    EXPECT_EQ(res, 3);

    res = c.book(1, 6); //
    EXPECT_EQ(res, 3);

    res = c.book(46, 50);
    EXPECT_EQ(res, 3);

    res = c.book(11, 18);
    EXPECT_EQ(res, 3);
}

TEST(p732, t2)
{
    p732::MyCalendarThree c;

    auto res = c.book(24, 40);
    EXPECT_EQ(res, 1);

    res = c.book(43, 50);
    EXPECT_EQ(res, 1);

    res = c.book(27, 43);
    EXPECT_EQ(res, 2);

    res = c.book(5, 21);
    EXPECT_EQ(res, 2);

    res = c.book(30, 40);
    EXPECT_EQ(res, 3);

    res = c.book(14, 29);
    EXPECT_EQ(res, 3);

    res = c.book(3, 19);
    EXPECT_EQ(res, 3);

    res = c.book(3, 14);
    EXPECT_EQ(res, 3);

    res = c.book(25, 39);
    EXPECT_EQ(res, 4);

    res = c.book(6, 19);
    EXPECT_EQ(res, 4);
}

TEST(p732, t3)
{
    p732::MyCalendarThree c;

    auto res = c.book(5, 21);
    EXPECT_EQ(res, 1);

    res = c.book(14, 29);
    EXPECT_EQ(res, 2);

    res = c.book(3, 19);
    EXPECT_EQ(res, 3);

    res = c.book(3, 14);
    EXPECT_EQ(res, 3);
}

TEST(p732, t4)
{
    p732::MyCalendarThree c;

    auto res = c.book(24, 40);
    EXPECT_EQ(res, 1);

    res = c.book(27, 43);
    EXPECT_EQ(res, 2);

    res = c.book(30, 40);
    EXPECT_EQ(res, 3);

    res = c.book(14, 29);
    EXPECT_EQ(res, 3);
}