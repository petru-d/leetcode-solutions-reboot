#include "pch.h"

#include "../problems/p129.h"

TEST(p129, t0)
{
    p129::Solution s;

    auto res = s.sumNumbers(make_binary_tree(1, 2, 3));

    EXPECT_EQ(res, 44);
}
