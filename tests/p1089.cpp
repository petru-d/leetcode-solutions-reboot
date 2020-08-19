#include "pch.h"

#include "../problems/p1089.h"

TEST(p1089, t0)
{
    p1089::Solution s;

    std::vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    s.duplicateZeros(arr);

    std::vector<int> expected = {1, 0, 0, 2, 3, 0, 0, 4};
    EXPECT_EQ(arr, expected);
}
