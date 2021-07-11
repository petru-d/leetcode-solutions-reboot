#include "pch.h"

#include "../problems/p1690.h"

TEST(p1690, t0)
{
    std::vector<int> stones = {5, 3, 1, 4, 2};
    p1690::Solution s;
    auto res = s.stoneGameVII(stones);
    EXPECT_EQ(res, 6);

    // first solution moves
    std::vector<int> stones2 = {5, 3, 1, 4, 2};
    p1690::Solution2 s2;
    auto res2 = s2.stoneGameVII(stones2);
    EXPECT_EQ(res2, 6);
}
