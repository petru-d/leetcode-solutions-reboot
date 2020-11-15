#include "pch.h"

#include "../problems/p228.h"

TEST(p228, t0)
{
    p228::Solution s;

    std::vector<int> n = { 0, 1, 2, 4, 5, 7};
    auto res = s.summaryRanges(n);

    ASSERT_EQ(res.size(), 3);

    EXPECT_EQ(res[0], "0->2");
    EXPECT_EQ(res[1], "4->5");
    EXPECT_EQ(res[2], "7");
}
