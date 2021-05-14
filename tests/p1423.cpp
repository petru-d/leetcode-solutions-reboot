#include "pch.h"

#include "../problems/p1423.h"

TEST(p1423, t0)
{
    std::vector<int> cards = {1, 2, 3, 4, 5, 6, 1};

    p1423::Solution s;
    auto res = s.maxScore(cards, 3);
    EXPECT_EQ(res, 12);

    p1423::Solution2 s2;
    res = s2.maxScore(cards, 3);
    EXPECT_EQ(res, 12);
}
