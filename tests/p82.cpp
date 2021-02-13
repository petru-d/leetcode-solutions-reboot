#include "pch.h"

#include "../problems/p82.h"

TEST(p82, t0)
{
    p82::Solution s;

    auto* res = s.deleteDuplicates(make_list({1, 2, 3, 3, 4, 4, 5}));

    EXPECT_TRUE(eq_lists(res, make_list({1,2,5})));
}
