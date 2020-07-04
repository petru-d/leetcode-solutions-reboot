#include "pch.h"

#include "../problems/p51.h"

TEST(p51, t0)
{
    p51::Solution s;

    auto res = s.solveNQueens(4);

    std::vector<std::vector<std::string>> expected = {{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}};

    EXPECT_EQ(res, expected);
}