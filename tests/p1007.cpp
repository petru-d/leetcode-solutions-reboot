#include "pch.h"

#include "../problems/p1007.h"

TEST(p1007, t0)
{
    p1007::Solution s;

    std::vector<int> A = {2, 1, 2, 4, 2, 2};
    std::vector<int> B = {5, 2, 6, 2, 3, 2};

    auto res = s.minDominoRotations(A, B);

    EXPECT_EQ(res, 2);
}
