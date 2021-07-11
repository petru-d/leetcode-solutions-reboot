#include "pch.h"

#include "../problems/p97.h"

TEST(p97, t0)
{
    auto a = "aabcc";
    auto b = "dbbca";
    auto c = "aadbbcbcac";

    p97::Solution s;
    auto r1 = s.isInterleave(a, b, c);
    EXPECT_TRUE(r1);

    p97::Solution2 s2;
    auto r2 = s2.isInterleave(a, b, c);
    EXPECT_TRUE(r2);
}
