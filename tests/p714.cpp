#include "pch.h"

#include "../problems/p714.h"

TEST(p714, t0)
{
    p714::Solution s;
    std::vector<int> prices{1, 3, 2, 8, 4, 9};
    auto res = s.maxProfit(prices, 2);
    EXPECT_EQ(res, 8);
}
