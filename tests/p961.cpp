#include "pch.h"

#include "../problems/p961.h"

TEST(p961, t0)
{
    p961::Solution s;

    std::vector<int> A = {5, 1, 5, 2, 5, 3, 5, 4};
    auto res = s.repeatedNTimes(A);

    EXPECT_EQ(res, 5);
}
