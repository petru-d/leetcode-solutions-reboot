#include "pch.h"

#include "../problems/p163.h"

TEST(p163, t0)
{
    p163::Solution s;
    std::vector<int> nums = {0, 1, 3, 50, 75};

    auto res = s.findMissingRanges(nums, 0, 99);

    std::vector<std::string> expected = {"2", "4->49", "51->74", "76->99"};
    EXPECT_EQ(res, expected);
    
}
