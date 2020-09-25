#include "pch.h"

#include "../problems/p134.h"

#include <fstream>

TEST(p134, t0)
{
    p134::Solution s;

    std::vector<int> gas = {1, 2, 3, 4, 5};
    std::vector<int> cost = {3, 4, 5, 1, 2};

    auto res = s.canCompleteCircuit(gas, cost);

    EXPECT_EQ(res, 3);
}

TEST(p134, t1)
{
    p134::Solution s;

    std::vector<int> gas = {2, 3, 4};
    std::vector<int> cost = {3, 4, 5};

    auto res = s.canCompleteCircuit(gas, cost);

    EXPECT_EQ(res, -1);
}

TEST(p134, t2)
{
    p134::Solution s;

    std::vector<int> gas = {3, 3, 4};
    std::vector<int> cost = {3, 4, 4};

    auto res = s.canCompleteCircuit(gas, cost);

    EXPECT_EQ(res, -1);
}