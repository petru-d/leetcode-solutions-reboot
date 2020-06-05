#include "pch.h"

#include "../problems/p528.h"

TEST(p528, t0)
{
    std::vector<int> w = {1};
    p528::Solution s(w);

    // kinda idiotic test but i don't want to bother writing a good one
    auto res = s.pickIndex();
    EXPECT_EQ(res, 0);
}