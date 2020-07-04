#include "pch.h"

#include "../problems/p957.h"

TEST(p957, t0)
{
    p957::Solution s;

    std::vector<int> cells = {0, 1, 0, 1, 1, 0, 0, 1};
    cells = s.prisonAfterNDays(cells, 7);

    std::vector<int> expected = {0, 0, 1, 1, 0, 0, 0, 0};

    EXPECT_EQ(cells, expected);
}

TEST(p957, t1)
{
    p957::Solution s;

    std::vector<int> cells = {1, 0, 0, 1, 0, 0, 1, 0};
    cells = s.prisonAfterNDays(cells, 1000000000);

    std::vector<int> expected = {0, 0, 1, 1, 1, 1, 1, 0};

    EXPECT_EQ(cells, expected);
}
