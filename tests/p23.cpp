#include "pch.h"

#include "../problems/p23.h"

TEST(p23, t0)
{
    p23::Solution s;

    auto* l1 = make_list({1, 3});
    auto* l2 = make_list({2, 4});

    std::vector<ListNode*> v = {l1, l2};

    auto* l = s.mergeKLists(v);

    EXPECT_TRUE(eq_lists(l, make_list({1, 2, 3, 4})));
}
