#include "pch.h"

#include "../problems/p495.h"

TEST(p495, t0)
{
    p495::Solution s;

    std::vector<int> attacks = {1, 4};

    auto res = s.findPoisonedDuration(attacks, 2);

    EXPECT_EQ(res, 4);
}

TEST(p495, t1)
{
    p495::Solution s;

    std::vector<int> attacks = {1, 2};

    auto res = s.findPoisonedDuration(attacks, 2);

    EXPECT_EQ(res, 3);
}
