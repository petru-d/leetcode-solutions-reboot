#include "pch.h"

#include "../problems/p119.h"

TEST(p119, t0)
{
    p119::Solution s;
    auto res = s.getRow(3);

    std::vector<int> expected = {1, 2, 1};
    EXPECT_EQ(res, expected);
}
