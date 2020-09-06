#include "pch.h"

#include "../problems/p949.h"

TEST(p949, t0)
{
    p949::Solution s;

    std::vector<int> digits = {1, 2, 3, 4};

    auto res = s.largestTimeFromDigits(digits);

    EXPECT_EQ(res, "23:41");
}
