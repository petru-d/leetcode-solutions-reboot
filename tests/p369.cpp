#include "pch.h"

#include "../problems/p369.h"

TEST(p369, t0)
{
    p369::Solution s;

    auto* l = s.plusOne(make_list({1, 2, 3}));

    EXPECT_TRUE(eq_lists(l, make_list({1, 2, 4})));
}
