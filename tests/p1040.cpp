#include "pch.h"

#include "../problems/p1040.h"

TEST(p1040, t0)
{
    std::vector<int> data = {7, 4, 9};
    p1040::Solution s;

    auto res = s.numMovesStonesII(data);
    EXPECT_EQ(res, std::vector<int>({1, 2}));
}
