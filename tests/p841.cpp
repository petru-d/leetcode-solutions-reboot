#include "pch.h"

#include "../problems/p841.h"

TEST(p841, t0)
{
    [[maybe_unused]] p841::Solution s;

    std::vector<std::vector<int>> rooms = {{1}, {2}, {3}, {}};
    auto res = s.canVisitAllRooms(rooms);
    EXPECT_TRUE(res);
}
