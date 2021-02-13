#include "pch.h"

#include "../problems/p1345.h"

TEST(p1345, t0)
{
    p1345::Solution s;

    std::vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    auto res = s.minJumps(arr);

    EXPECT_EQ(res, 3);
}
