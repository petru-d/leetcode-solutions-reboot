#include "pch.h"

#include "../problems/p1046.h"

TEST(p1046, t0)
{

    p1046::Solution s;
    std::vector<int> data = {2, 7, 4, 1, 8, 1};
    int res = s.lastStoneWeight(data);

    EXPECT_EQ(res, 1);
}

TEST(p1046, t1)
{

    p1046::Solution s;
    std::vector<int> data = {};
    int res = s.lastStoneWeight(data);

    EXPECT_EQ(res, 0);
}

TEST(p1046, t2)
{

    p1046::Solution s;
    std::vector<int> data = {1, 8, 7};
    int res = s.lastStoneWeight(data);

    EXPECT_EQ(res, 0);
}
