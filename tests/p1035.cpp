#include "pch.h"

#include "../problems/p1035.h"

TEST(p1035, t0)
{
    p1035::Solution s;

    std::vector<int> v1 = {2, 5, 1, 2, 5};
    std::vector<int> v2 = {5, 2, 1, 5, 2};
    auto res = s.maxUncrossedLines(v1, v2);

    EXPECT_EQ(res, 3);
}
