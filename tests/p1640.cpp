#include "pch.h"

#include "../problems/p1640.h"

TEST(p1640, t0)
{
     p1640::Solution s;

     std::vector<int> arr = {15, 88};
     std::vector<std::vector<int>> pieces = {{88}, {15}};

     auto res= s.canFormArray(arr, pieces);

     EXPECT_TRUE(res);
}
