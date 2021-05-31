#include "pch.h"

#include "../problems/p102.h"

TEST(p102, t0)
{
    auto* t = deserialize_tree("1(2,3)");

    p102::Solution s;
    auto res = s.levelOrder(t);
    EXPECT_EQ(res, std::vector<std::vector<int>>({{1}, {2, 3}}));

    p102::Solution2 s2;
    auto res2 = s2.levelOrder(t);
    EXPECT_EQ(res2, std::vector<std::vector<int>>({{1}, {2, 3}}));
}
