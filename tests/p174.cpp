#include "pch.h"

#include "../problems/p174.h"

TEST(p174, t0)
{
    p174::Solution s;

    std::vector<std::vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};

    auto min_hp = s.calculateMinimumHP(dungeon);

    EXPECT_EQ(min_hp, 7);
}
