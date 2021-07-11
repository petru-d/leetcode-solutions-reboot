#include "pch.h"

#include "../problems/p128.h"

TEST(p128, t0)
{
    std::vector<int> nums = {100, 4, 200, 1, 2, 3};

    p128::Solution s;
    auto res = s.longestConsecutive(nums);
    EXPECT_EQ(res, 4);

    p128::Solution2 s2;
    auto res2 = s2.longestConsecutive(nums);
    EXPECT_EQ(res2, 4);

    p128::Solution3 s3;
    auto res3 = s3.longestConsecutive(nums);
    EXPECT_EQ(res3, 4);

    p128::Solution4 s4;
    auto res4 = s4.longestConsecutive(nums);
    EXPECT_EQ(res4, 4);
}
