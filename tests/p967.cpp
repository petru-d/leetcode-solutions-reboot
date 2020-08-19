#include "pch.h"

#include "../problems/p967.h"

TEST(p967, t0)
{
    p967::Solution s;
    auto res = s.numsSameConsecDiff(3, 7);
    std::vector<int> expected = {181, 292, 707, 818, 929};
    EXPECT_EQ(res, expected);
}
