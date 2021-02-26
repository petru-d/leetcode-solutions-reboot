#include "pch.h"

#include "../problems/p141.h"

TEST(p141, t0)
{
    p141::Solution s;

    auto* l = make_list({1, 2, 3});
    l->next->next->next = l;

    auto res = s.hasCycle(l);

    EXPECT_TRUE(res);
}
