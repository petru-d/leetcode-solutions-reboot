#include "pch.h"

#include "../problems/p582.h"

TEST(p582, t0)
{
    p582::Solution s;
    std::vector<int> pid = {1, 3, 10, 5};
    std::vector<int> ppid = {3, 0, 5, 3};

    auto res = s.killProcess(pid, ppid, 5);

    std::vector<int> exp = {5, 10};
    EXPECT_TRUE(std::is_permutation(res.begin(), res.end(), exp.begin(), exp.end()));
}
