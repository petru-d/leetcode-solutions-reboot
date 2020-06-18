#include "pch.h"

#include "../problems/p275.h"

TEST(p275, t0)
{
    p275::Solution s;
    std::vector<int> citations = {0, 1, 3, 5, 6};
    auto res = s.hIndex(citations);
    EXPECT_EQ(res, 3);
}
