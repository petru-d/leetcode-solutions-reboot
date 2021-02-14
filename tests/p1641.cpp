#include "pch.h"

#include "../problems/p1641.h"

TEST(p1641, t0)
{
     p1641::Solution s;

     auto res = s.countVowelStrings(2);

     EXPECT_EQ(res, 15);
}
