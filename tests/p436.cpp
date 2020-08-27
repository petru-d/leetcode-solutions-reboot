#include "pch.h"

#include "../problems/p436.h"

TEST(p436, t0)
{
    p436::Solution s;

    std::vector<std::vector<int>> intervals = {{3, 4}, {2, 3}, {1, 2}};
    auto res = s.findRightInterval(intervals);

    std::vector<int> expected = {-1, 0, 1};
    EXPECT_EQ(res, expected);
}

TEST(p436, t1)
{
    p436::Solution s;

    std::vector<std::vector<int>> intervals = {{1, 2}};
    auto res = s.findRightInterval(intervals);

    std::vector<int> expected = {-1};
    EXPECT_EQ(res, expected);
}

TEST(p436, t2)
{
    p436::Solution s;

    std::vector<std::vector<int>> intervals = {{1, 4}, {2, 3}, {3, 4}};
    auto res = s.findRightInterval(intervals);

    std::vector<int> expected = {-1, 2, -1};
    EXPECT_EQ(res, expected);
}
