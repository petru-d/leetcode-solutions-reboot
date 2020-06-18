#include "pch.h"

#include "../problems/p474.h"

TEST(p474, t0)
{
    p474::Solution s;

    std::vector<std::string> strs = {"10", "0001", "111001", "1", "0"};

    auto res = s.findMaxForm(strs, 5, 3);

    EXPECT_EQ(res, 4);
}

TEST(p474, t1)
{
    p474::Solution s;

    std::vector<std::string> strs = {"10", "0", "1"};

    auto res = s.findMaxForm(strs, 1, 1);

    EXPECT_EQ(res, 2);
}
