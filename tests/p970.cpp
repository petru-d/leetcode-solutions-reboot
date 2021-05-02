#include "pch.h"

#include "../problems/p970.h"

TEST(p970, t0)
{
    p970::Solution s;

    auto res = s.powerfulIntegers(1, 1, 2);
    EXPECT_EQ(res, (std::vector<int>{2}));
}
