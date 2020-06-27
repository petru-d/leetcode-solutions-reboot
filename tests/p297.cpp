#include "pch.h"

#include "../problems/p297.h"

TEST(p297, t0)
{
    p297::Codec c;

    auto t2 = make_binary_tree(2);
    auto t3 = make_binary_tree(4, 3, 5);
    auto t = make_binary_tree(t2, 1, t3);
    auto ser = c.serialize(t);

    EXPECT_EQ(ser, "1(2,3(4,5))");
}

TEST(p297, t1)
{
    p297::Codec c;

    auto t = c.deserialize("1(2,3(4,5))");

    ASSERT_FALSE(t == nullptr);
    EXPECT_EQ(t->val, 1);

    ASSERT_FALSE(t->left == nullptr);
    EXPECT_EQ(t->left->val, 2);

    ASSERT_FALSE(t->right == nullptr);
    EXPECT_EQ(t->right->val, 3);

    ASSERT_FALSE(t->right->left == nullptr);
    EXPECT_EQ(t->right->left->val, 4);

    ASSERT_FALSE(t->right->right == nullptr);
    EXPECT_EQ(t->right->right->val, 5);
}

TEST(p297, t2)
{
    p297::Codec c;

    auto t1 = make_binary_tree(1);
    auto t2 = make_binary_tree(t1, 2, nullptr);
    auto t4 = make_binary_tree(4);
    auto t = make_binary_tree(t2, 3, t4);
    auto ser = c.serialize(t);

    EXPECT_EQ(ser, "3(2(1,),4)");
}

TEST(p297, t3)
{
    p297::Codec c;

    auto t = c.deserialize("3(2(1,),4)");

    ASSERT_FALSE(t == nullptr);
    EXPECT_EQ(t->val, 3);

    ASSERT_FALSE(t->left == nullptr);
    EXPECT_EQ(t->left->val, 2);

    ASSERT_FALSE(t->left->left == nullptr);
    EXPECT_EQ(t->left->left->val, 1);

    ASSERT_FALSE(t->right == nullptr);
    EXPECT_EQ(t->right->val, 4);
}

TEST(p297, t4)
{
    p297::Codec c;

    auto t4 = make_binary_tree(4);
    auto t3 = make_binary_tree(nullptr, 3, t4);
    auto t = make_binary_tree(t3, 1, nullptr);
    auto ser = c.serialize(t);

    EXPECT_EQ(ser, "1(3(,4),)");
}

TEST(p297, t5)
{
    p297::Codec c;

    auto t = c.deserialize("1(3(,4),)");

    ASSERT_FALSE(t == nullptr);
    EXPECT_EQ(t->val, 1);

    ASSERT_FALSE(t->left == nullptr);
    EXPECT_EQ(t->left->val, 3);

    ASSERT_FALSE(t->left->right == nullptr);
    EXPECT_EQ(t->left->right->val, 4);
}
