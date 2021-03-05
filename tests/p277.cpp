#include "pch.h"

#include "../problems/p277.h"

TEST(p277, t0)
{
    p277::Solution s({{0, 1}, {2, 1}, {2, 0}});
    auto res = s.findCelebrity(3);
    EXPECT_EQ(res, 1);
}
