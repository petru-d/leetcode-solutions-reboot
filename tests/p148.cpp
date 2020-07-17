#include "pch.h"

#include "../problems/p148.h"

TEST(p148, t0)
{
    p148::Solution s;

    auto res = s.sortList(make_list({4, 3, 2, 1}));

    auto exp = make_list({1, 2, 3, 4});

    EXPECT_TRUE(eq_lists(res, exp));
}
