#include "pch.h"

#include "../problems/p871.h"

TEST(p871, t0)
{
    p871::Solution s;

    std::vector<std::vector<int>> st = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};

    auto res = s.minRefuelStops(100, 10, st);

    EXPECT_EQ(res, 2);
}

TEST(p871, t1)
{
    p871::Solution s;

    std::vector<std::vector<int>> st = {{25, 25}, {50, 50}};

    auto res = s.minRefuelStops(100, 50, st);

    EXPECT_EQ(res, 1);
}

TEST(p871, t2)
{
    p871::Solution s;

    std::vector<std::vector<int>> st = {{25, 27},  {36, 187},  {140, 186}, {378, 6},  {492, 202},
                                        {517, 89}, {579, 234}, {673, 86},  {808, 53}, {954, 49}};

    auto res = s.minRefuelStops(1000, 83, st);

    EXPECT_EQ(res, -1);
}
