#include "pch.h"

#include "../problems/p637.h"

TEST(p637, t0)
{
    p637::Solution s;
    auto res = s.averageOfLevels(deserialize_tree("3(9,20(15,7))"));
    EXPECT_EQ(res, (std::vector<double>{3, 14.5, 11}));
}
