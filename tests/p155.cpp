#include "pch.h"

#include "../problems/p155.h"

TEST(p155, t0)
{
    p155::MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);

    EXPECT_EQ(obj.getMin(), -3);
    obj.pop();
    EXPECT_EQ(obj.top(), 0);
    EXPECT_EQ(obj.getMin(), -2);
}
