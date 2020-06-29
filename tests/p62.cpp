#include "pch.h"

#include "../problems/p62.h"

TEST(p62, t0)
{
    p62::Solution s;

    auto res = s.uniquePaths(3, 2);

    EXPECT_EQ(res, 3);
}
