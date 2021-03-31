#include "pch.h"

#include "../problems/p354.h"

TEST(p354, t0)
{
    std::vector<std::vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};

    p354::Solution s;
    auto res = s.maxEnvelopes(envelopes);
    EXPECT_EQ(res, 3);

    p354::Solution2 s2;
    res = s2.maxEnvelopes(envelopes);
    EXPECT_EQ(res, 3);
}
