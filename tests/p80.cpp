#include "pch.h"

#include "../problems/p80.h"

TEST(p80, t0)
{
     p80::Solution s;

     std::vector<int> nums = {1, 1, 1, 2, 2, 3};
     auto res = s.removeDuplicates(nums);
     EXPECT_EQ(res, 5);
}
