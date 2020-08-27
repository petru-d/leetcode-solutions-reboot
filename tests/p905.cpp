#include "pch.h"

#include "../problems/p905.h"

TEST(p905, t0)
{
    p905::Solution s;

    std::vector<int> A = {3, 1, 2, 4};
    auto res = s.sortArrayByParity(A);

    EXPECT_TRUE(res.size() == 4 && res[0] % 2 == 0 && res[1] % 2 == 0 && res[2] % 2 == 1 && res[3] % 2 == 1);
}
