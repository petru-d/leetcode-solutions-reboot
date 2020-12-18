#include "pch.h"

#include "../problems/p77.h"

TEST(p77, t0)
{
    p77::Solution s;
    auto res = s.combine(1, 1);
    std::vector<std::vector<int>> expected = {{1}};
    EXPECT_EQ(res, expected);
}
