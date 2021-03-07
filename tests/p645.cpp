#include "pch.h"

#include "../problems/p645.h"

TEST(p645, t0)
{
    p645::Solution s;

    std::vector<int> nums = {1, 2, 2, 4};

    auto res = s.findErrorNumsleetcode(nums);
    EXPECT_EQ(res, (std::vector<int>{2, 3}));

    res = s.findErrorNumsMine(nums);
    EXPECT_EQ(res, (std::vector<int>{2, 3}));
}
