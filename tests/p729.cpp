#include "pch.h"

#include "../problems/p729.h"

TEST(p729, t0)
{
    p729::MyCalendar c;

    auto res = c.book(10, 20);
    EXPECT_TRUE(res);

    res = c.book(15, 25);
    EXPECT_FALSE(res);

    res = c.book(20, 30);
    EXPECT_TRUE(res);
}
