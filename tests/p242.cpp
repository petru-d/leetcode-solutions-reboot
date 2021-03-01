#include "pch.h"

#include "../problems/p242.h"

TEST(p242, t0)
{
    p242::Solution s;

    auto res = s.isAnagram("ana", "gram");
    EXPECT_FALSE(res);
}
