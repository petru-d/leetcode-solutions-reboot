#include "pch.h"

#include "../problems/p835.h"

TEST(p835, t0)
{
    p835::Solution s;

    std::vector<std::vector<int>> A = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    std::vector<std::vector<int>> B = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};

    auto res = s.largestOverlap(A, B);
    EXPECT_EQ(res, 3);
}
