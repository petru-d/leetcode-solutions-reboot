#include "pch.h"

#include "../problems/p99.h"

TEST(p99, t0)
{
    p99::Solution s;

    auto* t = deserialize_tree("1(3(,2),)");

    s.recoverTree(t);

    auto ser = serialize_tree(t);

    EXPECT_EQ(ser, "3(1(,2),)");
}

TEST(p99, t1)
{
    p99::Solution s;

    auto* t = deserialize_tree("0(1,)");

    s.recoverTree(t);

    auto ser = serialize_tree(t);

    EXPECT_EQ(ser, "1(0,)");
}

TEST(p99, t2)
{
    p99::Solution s;

    auto* t = deserialize_tree("146(71(55(321(-33,),),),-13(231,399))");

    s.recoverTree(t);

    auto ser = serialize_tree(t);

    EXPECT_EQ(ser, "146(71(55(-13(-33,),),),321(231,399))");
}
