#include "pch.h"

#include "../problems/p1337.h"

TEST(p1337, t0)
{
    p1337::Solution s;

    std::vector<std::vector<int>> mat = {{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};

    auto res = s.kWeakestRows(mat, 3);

    EXPECT_EQ(res, (std::vector<int>{2, 0, 3}));
}
