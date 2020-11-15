#include "pch.h"

#include "../problems/p310.h"

TEST(p310, t0)
{
    p310::Solution s;

    std::vector<std::vector<int>> edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    auto res = s.findMinHeightTrees(6, edges);

    ASSERT_EQ(res.size(), 2);

    EXPECT_TRUE(res[0] == 3 || res[0] == 4);
    EXPECT_TRUE(res[1] == 3 || res[1] == 4);
}
