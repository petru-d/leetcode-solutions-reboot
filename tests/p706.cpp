#include "pch.h"

#include "../problems/p706.h"

TEST(p706, t0)
{
    p706::MyHashMap h;
    h.put(1, 1);
    h.put(2, 2);
    auto res = h.get(1);
    EXPECT_EQ(res, 1);
}
