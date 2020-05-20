#include "pch.h"

#include "../problems/p225.h"

TEST(p225, t0)
{
    p225::MyStack s;
    s.push(1);
    s.push(2);
    auto res = s.top();
    EXPECT_EQ(res, 2);
    res = s.pop();
    EXPECT_EQ(res, 2);
    auto e = s.empty();
    EXPECT_EQ(e, false);
}