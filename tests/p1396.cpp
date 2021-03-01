#include "pch.h"

#include "../problems/p1396.h"

TEST(p1396, t0)
{

    p1396::UndergroundSystem u;

    u.checkIn(10, "Leyton", 3);
    u.checkOut(10, "Paradise", 8);
    auto res = u.getAverageTime("Leyton", "Paradise");
    EXPECT_NEAR(res, 5, 0.0001);
    u.checkIn(5, "Leyton", 10);
    u.checkOut(5, "Paradise", 16);
    res = u.getAverageTime("Leyton", "Paradise");
    EXPECT_NEAR(res, 5.5, 0.0001);
}
