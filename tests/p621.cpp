#include "pch.h"

#include "../problems/p621.h"

TEST(p621, t0)
{
    p621::Solution s;

    std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    auto res = s.leastInterval(tasks, 2);

    EXPECT_EQ(res, 8);
}
