#include "pch.h"

#include "../problems/p147.h"

TEST(p147, t0)
{
    p147::Solution s;

    auto* l = s.insertionSortList(make_list({4, 2, 1, 3}));

    EXPECT_TRUE(eq_lists(l, make_list({1, 2, 3, 4})));
}
