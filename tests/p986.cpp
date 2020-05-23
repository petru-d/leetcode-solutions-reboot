#include "pch.h"

#include "../problems/p986.h"

TEST(p986, t0)
{
    std::vector<std::vector<int>> A = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    std::vector<std::vector<int>> B = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};

    p986::Solution s;
    auto res = s.intervalIntersection(A, B);

    std::vector<std::vector<int>> expected = {{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}};

    EXPECT_EQ(res, expected);
}

TEST(p986, t1)
{
    std::vector<std::vector<int>> A = {{5, 10}};
    std::vector<std::vector<int>> B = {{6, 8}};

    p986::Solution s;
    auto res = s.intervalIntersection(A, B);

    std::vector<std::vector<int>> expected = {{6, 8}};

    EXPECT_EQ(res, expected);
}
