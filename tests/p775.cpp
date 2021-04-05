#include "pch.h"

#include "../problems/p775.h"

TEST(p775, t0)
{
    p775::Solution s;
    std::vector<int> A = {0, 1, 2};
    auto res = s.isIdealPermutation(A);
    EXPECT_TRUE(res);
}
