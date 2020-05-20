#include "pch.h"

#include "../problems/p109.h"

TEST(p109, t0)
{
    auto* tm10 = make_binary_tree(-10);
    auto* tm3 = make_binary_tree(tm10, -3, nullptr);
    auto* t5 = make_binary_tree(5);
    auto* t9 = make_binary_tree(t5, 9, nullptr);
    auto* t0 = make_binary_tree(tm3, 0, t9);

    p109::Solution s;
    std::vector<int> nums = {-10, -3, 0, 5, 9};
    auto* res = s.sortedListToBST(make_list(nums));

    bool eq = equal_trees(t0, res);
    EXPECT_EQ(eq, true);
}