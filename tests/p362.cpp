#include "pch.h"

#include "../problems/p362.h"

TEST(p362, t0)
{
    p362::HitCounter h;
    h.hit(1);
    h.hit(2);
    h.hit(3);
    auto hits = h.getHits(4);
    EXPECT_EQ(hits, 3);
}
