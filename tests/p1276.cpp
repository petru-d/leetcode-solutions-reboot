#include "pch.h"

#include "../problems/p1276.h"

TEST(p1276, t0)
{
    p1276::Solution s;
    auto res = s.numOfBurgers(16, 7);

    std ::vector<int> expected = {1, 6};
    EXPECT_EQ(res, expected);
}
