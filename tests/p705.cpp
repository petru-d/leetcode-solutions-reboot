#include "pch.h"

#include "../problems/p705.h"

TEST(p705, t0)
{
    p705::MyHashSet h;
    h.add(1);
    auto res = h.contains(1);
    EXPECT_TRUE(res);
}
