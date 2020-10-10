#include "pch.h"

#include "../problems/p1288.h"

TEST(p1288, t0)
{
    p1288::Solution s;

    std::vector<std::vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    auto res = s.removeCoveredIntervals(intervals);

    EXPECT_EQ(res, 2);
}
