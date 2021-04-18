#include "pch.h"

#include "../problems/p19.h"

TEST(p19, t0)
{
    p19::Solution s;
    auto* res = s.removeNthFromEnd(make_list({1, 2, 3, 4, 5}), 2);

    EXPECT_TRUE(eq_lists(res, make_list({1, 2, 3, 5})));
}
