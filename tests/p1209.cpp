#include "pch.h"

#include "../problems/p1209.h"

TEST(p1209, t0)
{
    p1209::Solution s;
    auto res = s.removeDuplicates("deeedbbcccbdaa", 3);
    EXPECT_EQ(res, "aa");

    p1209::Solution2 s2;
    res = s2.removeDuplicates("deeedbbcccbdaa", 3);
    EXPECT_EQ(res, "aa");
}
