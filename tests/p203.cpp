#include "pch.h"

#include "../problems/p203.h"

TEST(p203, t0)
{
    p203::Solution s;
    auto* res = s.removeElements(make_list({1, 2, 6, 3, 4, 5, 6}), 6);

    EXPECT_TRUE(eq_lists(res, make_list({1, 2, 3, 4, 5})));
}