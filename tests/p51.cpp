#include "pch.h"

#include "../problems/p51.h"

TEST(p51, t0)
{
    std::vector<std::vector<std::string>> expected = {{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}};

    p51::Solution s;
    auto res = s.solveNQueens(4);
    EXPECT_TRUE(std::is_permutation(res.begin(), res.end(), expected.begin(), expected.end()));

    p51::Solution2 s2;
    auto res2 = s2.solveNQueens(4);
    EXPECT_TRUE(std::is_permutation(res2.begin(), res2.end(), expected.begin(), expected.end()));
}