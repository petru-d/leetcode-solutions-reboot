#include "pch.h"

#include "../problems/p450.h"

TEST(p450, t0)
{
    p450::Solution s;

    auto* t = deserialize_tree("40(20(10(5,15),30(25,35)),60(50,70))");
    t = s.deleteNode(t, 20);

    EXPECT_EQ("40(25(10(5,15),30(,35)),60(50,70))", serialize_tree(t));
}

TEST(p450, t1)
{
    p450::Solution s;

    auto* t = deserialize_tree("40(20(10(5,15),30(25,35)),60(50,70))");
    t = s.deleteNode(t, 40);

    EXPECT_EQ("50(20(10(5,15),30(25,35)),60(,70))", serialize_tree(t));
}

TEST(p450, t2)
{
    p450::Solution s;

    auto* t = deserialize_tree("0");
    t = s.deleteNode(t, 0);

    EXPECT_EQ("", serialize_tree(t));
}
