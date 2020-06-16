#include "pch.h"

#include "../problems/p118.h"

TEST(p118, t0)
{
    p118::Solution s;
    auto res = s.generate(3);

    std::vector<std::vector<int>> expected = {{1}, {1, 1}, {1, 2, 1}};
    EXPECT_EQ(res, expected);
}
