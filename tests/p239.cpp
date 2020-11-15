#include "pch.h"

#include "../problems/p239.h"

TEST(p239, t0)
{
     p239::Solution s;

     std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
     auto res = s.maxSlidingWindow(nums, 3);

     EXPECT_EQ(res, std::vector<int>({3,3,5,5,6,7}));
}
