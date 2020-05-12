#include "pch.h"

#include "../problems/p733.h"

TEST(p733, t0)
{
    std::vector<std::vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

    p733::Solution s;
    auto res = s.floodFill(image, 1, 1, 2);

    std::vector<std::vector<int>> expected = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};

    EXPECT_EQ(res, expected);
}
