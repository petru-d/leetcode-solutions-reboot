#include "pch.h"

#include "../problems/p57.h"

TEST(p57, t0)
{
    p57::Solution s;

    std::vector<std::vector<int>> intervals = {{1, 3}, {6, 9}};
    std::vector<int> new_interval = {2, 5};

    auto res = s.insert(intervals, new_interval);

    std::vector<std::vector<int>> expected = {{1, 5}, {6, 9}};

    EXPECT_EQ(res, expected);
}

TEST(p57, t1)
{
    p57::Solution s;

    std::vector<std::vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    std::vector<int> new_interval = {4, 8};

    auto res = s.insert(intervals, new_interval);

    std::vector<std::vector<int>> expected = {{1, 2}, {3, 10}, {12, 16}};

    EXPECT_EQ(res, expected);
}
