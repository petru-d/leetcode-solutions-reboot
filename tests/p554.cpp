#include "pch.h"

#include "../problems/p554.h"

TEST(p554, t0)
{
    std::vector<std::vector<int>> wall = {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};
    p554::Solution s;
    auto res = s.leastBricks(wall);
    EXPECT_EQ(res, 2);

    p554::Solution2 s2;
    auto res2 = s2.leastBricks(wall);
    EXPECT_EQ(res2, 2);
}
