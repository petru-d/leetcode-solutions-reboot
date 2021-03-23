#include "pch.h"

#include "../problems/p923.h"

TEST(p923, t0)
{
    p923::Solution s;
    std::vector<int> arr = {1, 1, 2, 2, 3};
    auto res = s.threeSumMulti(arr, 5);
    EXPECT_EQ(res, 3);
}
