#include "pch.h"

#include "../problems/p380.h"

TEST(p380, t0)
{
    p380::RandomizedSet s;

    auto res = s.insert(1);
    EXPECT_TRUE(res);

    res = s.remove(2);
    EXPECT_FALSE(res);

    res = s.insert(2);
    EXPECT_TRUE(res);

    auto r = s.getRandom();
    EXPECT_TRUE(r == 1 || r == 2);

    res = s.remove(1);
    EXPECT_TRUE(res);

    res = s.insert(2);
    EXPECT_FALSE(res);

    r = s.getRandom();
    EXPECT_EQ(r, 2);
}

TEST(p380, t1)
{
    p380::RandomizedSet s;

    auto res = s.remove(0);
    EXPECT_FALSE(res);

    res = s.remove(0);
    EXPECT_FALSE(res);

    res = s.insert(0);
    EXPECT_TRUE(res);

    auto r = s.getRandom();
    EXPECT_TRUE(r == 0);

    res = s.remove(0);
    EXPECT_TRUE(res);

    res = s.insert(0);
    EXPECT_TRUE(res);
}

TEST(p380, t2)
{
    p380::RandomizedSet s;

    auto res = s.insert(0);
    EXPECT_TRUE(res);

    res = s.insert(2);
    EXPECT_TRUE(res);

    res = s.insert(1);
    EXPECT_TRUE(res);

    res = s.insert(1);
    EXPECT_FALSE(res);

    res = s.insert(1);
    EXPECT_FALSE(res);

    res = s.remove(0);
    EXPECT_TRUE(res);

    res = s.insert(0);
    EXPECT_TRUE(res);

    auto r = s.getRandom();
    EXPECT_TRUE(r == 0 || r == 1 || r == 2);

    res = s.insert(1);
    EXPECT_FALSE(res);

    res = s.remove(2);
    EXPECT_TRUE(res);
}
