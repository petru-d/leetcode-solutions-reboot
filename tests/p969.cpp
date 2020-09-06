#include "pch.h"

#include "../problems/p969.h"

TEST(p969, t0)
{
    p969::Solution s;

    std::vector<int> A = {3, 2, 4, 1};
    auto res = s.pancakeSort(A);

    std::vector<int> expected = {3, 4, 2, 3, 2};

    EXPECT_EQ(res, expected);
}
