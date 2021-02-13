#include "pch.h"

#include "../problems/p24.h"

TEST(p24, t0)
{
    p24::Solution s;

    auto* swapped = s.swapPairs(make_list({1, 2, 3, 4}));

    EXPECT_TRUE(eq_lists(swapped, make_list({2, 1, 4, 3})));
}
