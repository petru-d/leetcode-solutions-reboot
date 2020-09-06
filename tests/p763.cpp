#include "pch.h"

#include "../problems/p763.h"

TEST(p763, t0)
{
    p763::Solution s;

    auto res = s.partitionLabels("ababcbacadefegdehijhklij");

    std::vector<int> expected = {9, 7, 8};

    EXPECT_EQ(res, expected);
}
