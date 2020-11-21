#include "pch.h"

#include "../problems/p432.h"

TEST(p432, t0)
{
    p432::AllOne ao;

    ao.inc("mama");
    ao.inc("papa");
    ao.inc("mama");

    EXPECT_EQ(ao.getMinKey(), "papa");
    EXPECT_EQ(ao.getMaxKey(), "mama");

    ao.inc("papa");
    ao.inc("papa");
    ao.inc("papa");

    EXPECT_EQ(ao.getMinKey(), "mama");
    EXPECT_EQ(ao.getMaxKey(), "papa");
}

TEST(p432, t1)
{
    p432::AllOne ao;

    ao.inc("a");
    ao.inc("b");
    ao.inc("b");
    ao.inc("c");
    ao.inc("c");
    ao.inc("c");
    ao.dec("b");
    ao.dec("b");

    EXPECT_EQ(ao.getMinKey(), "a");

    ao.dec("a");

    EXPECT_EQ(ao.getMaxKey(), "c");
    EXPECT_EQ(ao.getMinKey(), "c");
}
