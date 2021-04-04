#include "pch.h"

#include "../problems/p622.h"

TEST(p622, t0)
{
    p622::MyCircularQueue qq(3);

    auto res = qq.enQueue(1);
    EXPECT_TRUE(res);
    res = qq.enQueue(2);
    EXPECT_TRUE(res);
    res = qq.enQueue(3);
    EXPECT_TRUE(res);
    res = qq.enQueue(4);
    EXPECT_FALSE(res);
    auto r = qq.Rear();
    EXPECT_EQ(r, 3);
}
