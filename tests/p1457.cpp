#include "pch.h"

#include "../problems/p1457.h"

TEST(p1457, t0)
{
    p1457::Solution s;

    auto res = s.pseudoPalindromicPaths(deserialize_tree("2(3(3,1),1(,1))"));
    
    EXPECT_EQ(res, 2);
}
