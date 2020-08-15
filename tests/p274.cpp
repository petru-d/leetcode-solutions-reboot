#include "pch.h"

#include "../problems/p274.h"

TEST(p274, t0)
{
    p274::Solution s;

    std::vector<int> citations = {3, 0, 6, 1, 5};
    auto res = s.hIndex(citations);

    EXPECT_EQ(res, 3);
}
