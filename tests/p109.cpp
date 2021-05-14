#include "pch.h"

#include "../problems/p109.h"

TEST(p109, t0)
{
    auto* tm10 = make_binary_tree(-10);
    auto* tm3 = make_binary_tree(tm10, -3, nullptr);
    auto* t5 = make_binary_tree(5);
    auto* t9 = make_binary_tree(t5, 9, nullptr);
    auto* t0 = make_binary_tree(tm3, 0, t9);

    std::vector<int> nums = {-10, -3, 0, 5, 9};

    p109::Solution s;
    auto* res = s.sortedListToBST(make_list(nums));
    EXPECT_TRUE(equal_trees(t0, res));

    p109::Solution2 s2;
    auto* res2 = s2.sortedListToBST(make_list(nums));
    EXPECT_TRUE(equal_trees(t0, res2));
}