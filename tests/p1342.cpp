#include "pch.h"

#include "../problems/p1342.h"

TEST(p1342, t0)
{
    [[maybe_unused]] p1342::Solution s;

    auto res = s.numberOfSteps(14);
    EXPECT_EQ(res, 6);
}
