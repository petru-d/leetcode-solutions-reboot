#include "pch.h"

#include "../problems/challenge_30apr2020.h"

TEST(challenge_30apr2020, t0)
{
    // left subtree
    auto* zo = make_binary_tree(0, make_binary_tree(1)); // null <- 0 -> 1
    auto* zoz = make_binary_tree(0, 1, 0);               // 0 <- 1 -> 0
    auto* o = make_binary_tree(zo, 1, zoz);

    // right subtree
    auto* zz = make_binary_tree(make_binary_tree(0), 0, nullptr);

    // root
    auto* root = make_binary_tree(o, 0, zz);

    challenge_30apr2020::Solution s;

    std::vector<int> data = {0, 1, 0, 1};
    bool res = s.isValidSequence(root, data);

    EXPECT_EQ(res, true);
}

TEST(challenge_30apr2020, t1)
{
    // left subtree
    auto* zo = make_binary_tree(0, make_binary_tree(1)); // null <- 0 -> 1
    auto* zoz = make_binary_tree(0, 1, 0);               // 0 <- 1 -> 0
    auto* o = make_binary_tree(zo, 1, zoz);

    // right subtree
    auto* zz = make_binary_tree(make_binary_tree(0), 0, nullptr);

    // root
    auto* root = make_binary_tree(o, 0, zz);

    challenge_30apr2020::Solution s;

    std::vector<int> data = {0, 0, 1};
    bool res = s.isValidSequence(root, data);

    EXPECT_EQ(res, false);
}

TEST(challenge_30apr2020, t2)
{
    // left subtree
    auto* zo = make_binary_tree(0, make_binary_tree(1)); // null <- 0 -> 1
    auto* zoz = make_binary_tree(0, 1, 0);               // 0 <- 1 -> 0
    auto* o = make_binary_tree(zo, 1, zoz);

    // right subtree
    auto* zz = make_binary_tree(make_binary_tree(0), 0, nullptr);

    // root
    auto* root = make_binary_tree(o, 0, zz);

    challenge_30apr2020::Solution s;

    std::vector<int> data = {0, 1, 1};
    bool res = s.isValidSequence(root, data);

    EXPECT_EQ(res, false);
}

TEST(challenge_30apr2020, t3)
{
    // left subtree
    auto* t1 = make_binary_tree(nullptr, 1, make_binary_tree(8));
    auto* t9 = make_binary_tree(nullptr, 9, t1);

    // right subtree
    auto* t3 = make_binary_tree(nullptr, 3, make_binary_tree(2));

    // root
    auto* root = make_binary_tree(t9, 2, t3);

    challenge_30apr2020::Solution s;

    std::vector<int> data = {2, 9, 1, 8, 0};
    bool res = s.isValidSequence(root, data);

    EXPECT_EQ(res, false);
}
