#include "pch.h"

#include "../problems/p237.h"

TEST(p237, t0)
{
    p237::Solution s;

    auto* l = make_list({1, 2, 3});
    s.deleteNode(l);

    auto* expected = make_list({2, 3});
    EXPECT_TRUE(eq_lists(l, expected));
}