#include "pch.h"

#include "../problems/p169.h"

TEST(p169, t0)
{
    p169::Solution s;
    std::vector<int> data = {3, 2, 3};
    auto res = s.majorityElement(data);
    EXPECT_EQ(res, 3);
}