#include "pch.h"

#include "../problems/p1721.h"

TEST(p1721, t0)
{
    p1721::Solution s;

    auto* res = s.swapNodes(make_list({1, 2, 3, 4}), 1);
    EXPECT_TRUE(eq_lists(res, make_list({4, 2, 3, 1})));
}
