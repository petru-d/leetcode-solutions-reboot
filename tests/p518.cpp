#include "pch.h"

#include "../problems/p518.h"

TEST(p518, t0)
{
    p518::Solution s;

    std::vector<int> coins = {1, 2, 5};
    auto res = s.change(5, coins);

    EXPECT_EQ(res, 4);
}