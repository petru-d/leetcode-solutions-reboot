#include "pch.h"

#include "../problems/p593.h"

TEST(p593, t0)
{
    p593::Solution s;

    std::vector<int> p1 = {0, 0};
    std::vector<int> p2 = {0, 1};
    std::vector<int> p3 = {1, 0};
    std::vector<int> p4 = {1, 1};

    auto res = s.validSquare(p1, p2, p3, p4);

    EXPECT_TRUE(res);
}
