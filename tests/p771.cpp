#include "pch.h"

#include "../problems/p771.h"

TEST(p771, t0)
{
    p771::Solution s;
    auto res = s.numJewelsInStones("aA", "aAAbbbb");

    EXPECT_EQ(res, 3);
}

TEST(p771, t1)
{
    p771::Solution s;
    auto res = s.numJewelsInStones("z", "ZZ");

    EXPECT_EQ(res, 0);
}
