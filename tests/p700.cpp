#include "pch.h"

#include "../problems/p700.h"

TEST(p700, t0)
{
    p700::Solution s;
    auto* t = make_binary_tree(1, 2, 3);

    auto* tt = s.searchBST(t, 3);

    EXPECT_EQ(tt->val, 3);
}
