#include "pch.h"

#include "../problems/p39.h"

TEST(p39, t0)
{
    p39::Solution s;

    std::vector<int> candidates = {2, 3, 6, 7};

    auto res = s.combinationSum(candidates, 7);

    EXPECT_TRUE(res.size() == 2);

    std::vector<int> exp0 = {2, 2, 3};
    EXPECT_EQ(res[0], exp0);

    std::vector<int> exp1 = {7};
    EXPECT_EQ(res[1], exp1);
}
