#include "pch.h"

#include "../problems/p1103.h"

TEST(p1103, t0)
{
    p1103::Solution s;
    auto result = s.distributeCandies(7, 4);

    std::vector<int> expected = {1, 2, 3, 1};
    EXPECT_EQ(result, expected);
}
TEST(p1103, t1)
{
    p1103::Solution s;
    auto result = s.distributeCandies(10, 3);

    std::vector<int> expected = {5, 2, 3};
    EXPECT_EQ(result, expected);
}