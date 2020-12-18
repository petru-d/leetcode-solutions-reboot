#include "pch.h"

#include "../problems/p605.h"

TEST(p605, t0)
{
    p605::Solution s;

    std::vector<int> flowerbed = {1, 0, 0, 0, 1};
    auto res = s.canPlaceFlowers(flowerbed, 1);

    EXPECT_TRUE(res);
}
