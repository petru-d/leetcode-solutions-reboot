#include "pch.h"

#include "../problems/p66.h"

TEST(p66, t0)
{
    p66::Solution s;
    std::vector<int> num = {1, 2, 3};
    auto res = s.plusOne(num);

    std::vector<int> exp = {1, 2, 4};
    EXPECT_EQ(res, exp);
}
