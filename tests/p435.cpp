#include "pch.h"

#include "../problems/p435.h"

TEST(p435, t0)
{
    p435::Solution s;

    std::vector<std::vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    auto res = s.eraseOverlapIntervals(intervals);

    EXPECT_EQ(res, 1);
}

TEST(p435, t1)
{
    p435::Solution s;

    std::vector<std::vector<int>> intervals = {{1, 2}, {1, 2}, {1, 2}};
    auto res = s.eraseOverlapIntervals(intervals);

    EXPECT_EQ(res, 2);
}

TEST(p435, t2)
{
    p435::Solution s;

    std::vector<std::vector<int>> intervals = {{1, 2}, {2, 3}};
    auto res = s.eraseOverlapIntervals(intervals);

    EXPECT_EQ(res, 0);
}

TEST(p435, t3)
{
    p435::Solution s;

    std::vector<std::vector<int>> intervals = {{0, 2}, {1, 3}, {1, 3}, {2, 4}, {3, 5}, {3, 5}, {4, 6}};
    auto res = s.eraseOverlapIntervals(intervals);

    EXPECT_EQ(res, 4);
}
