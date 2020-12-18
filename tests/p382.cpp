#include "pch.h"

#include "../problems/p382.h"

TEST(p382, t0)
{
    p382::Solution s(make_list({1,2,3}));

    auto res = s.getRandom();

    EXPECT_TRUE(1 <= res && res <= 3);
}
