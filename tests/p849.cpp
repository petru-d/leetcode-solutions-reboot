#include "pch.h"

#include "../problems/p849.h"

TEST(p849, t0)
{
    p849::Solution s;

    std::vector<int> data = {1, 0, 0, 0, 1, 0, 1};
    auto res = s.maxDistToClosest(data);
    EXPECT_EQ(res, 2);
}

TEST(p849, t1)
{
    p849::Solution s;

    std::vector<int> data = {1, 0, 0, 0};
    auto res = s.maxDistToClosest(data);
    EXPECT_EQ(res, 3);
}

TEST(p849, t2)
{
    p849::Solution s;

    std::vector<int> data = {0, 0, 0, 1};
    auto res = s.maxDistToClosest(data);
    EXPECT_EQ(res, 3);
}
