#include "pch.h"

#include "../problems/p1229.h"

TEST(p1229, t0)
{
    [[maybe_unused]] p1229::Solution s;

    std::vector<std::vector<int>> slots1 = {{10, 50}, {60, 120}, {140, 210}};
    std::vector<std::vector<int>> slots2 = {{0, 15}, {60, 70}};
    auto res = s.minAvailableDuration(slots1, slots2, 8);

    EXPECT_EQ(res, (std::vector<int>{60, 68}));
}
