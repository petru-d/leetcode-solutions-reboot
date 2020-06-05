#include "pch.h"

#include "../problems/p983.h"

TEST(p983, t0)
{
    p983::Solution s;

    std::vector<int> days = {1, 4, 6, 7, 8, 20};
    std::vector<int> costs = {2, 7, 15};

    auto res = s.mincostTickets(days, costs);
    EXPECT_EQ(res, 11);
}

TEST(p983, t1)
{
    p983::Solution s;

    std::vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    std::vector<int> costs = {2, 7, 15};

    auto res = s.mincostTickets(days, costs);
    EXPECT_EQ(res, 17);
}

TEST(p983, t2)
{
    p983::Solution s;

    std::vector<int> days = {1, 4, 6, 7, 8, 20};
    std::vector<int> costs = {7, 2, 15};

    auto res = s.mincostTickets(days, costs);
    EXPECT_EQ(res, 6);
}

TEST(p983, t3)
{
    p983::Solution s;

    std::vector<int> days = {1, 2, 3, 4, 6};
    std::vector<int> costs = {3, 14, 50};

    auto res = s.mincostTickets(days, costs);
    EXPECT_EQ(res, 14);
}

TEST(p983, t4)
{
    p983::Solution s;

    std::vector<int> days = {1, 2, 3, 4, 6, 8, 9, 10, 13, 14, 16, 17, 19, 21, 24, 26, 27, 28, 29};
    std::vector<int> costs = {3, 14, 50};

    auto res = s.mincostTickets(days, costs);
    EXPECT_EQ(res, 50);
}
