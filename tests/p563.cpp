#include "pch.h"

#include "../problems/p563.h"

TEST(p563, t0)
{
    p563::Solution s;

    auto t = s.findTilt(make_binary_tree(2, 1, 3));

    EXPECT_EQ(t, 1);
}
