#include "pch.h"

#include "../problems/p107.h"

TEST(P107, T0)
{
    p107::Solution s;

    auto* t20 = make_binary_tree(15, 20, 7);
    auto* t9 = make_binary_tree(9);
    auto* t3 = make_binary_tree(t9, 3, t20);

    auto res = s.levelOrderBottom(t3);

    std::vector<std::vector<int>> expected = {{15, 7}, {9, 20}, {3}};

    EXPECT_EQ(res, expected);
}

TEST(P107, T1)
{
    p107::Solution s;

    auto res = s.levelOrderBottom(nullptr);

    std::vector<std::vector<int>> expected = {};

    EXPECT_EQ(res, expected);
}
