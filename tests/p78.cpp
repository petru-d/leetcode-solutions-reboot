#include "pch.h"

#include "../problems/p78.h"

TEST(p78, t0)
{
    std::vector<int> nums = {1, 2};
    p78::Solution s;
    auto subs = s.subsets(nums);

    std::vector<std::vector<int>> subs_exp = {{}, {1}, {2}, {1, 2}};

    EXPECT_EQ(subs, subs_exp);
}
