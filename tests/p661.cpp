#include "pch.h"

#include "../problems/p661.h"

TEST(p661, t0)
{
    p661::Solution s;
    std::vector<std::vector<int>> img = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    auto res = s.imageSmoother(img);
    EXPECT_EQ(res, (std::vector<std::vector<int>>{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}));
}
