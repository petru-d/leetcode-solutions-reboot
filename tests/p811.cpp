#include "pch.h"

#include "../problems/p811.h"

TEST(p811, t0)
{
    p811::Solution s;
    std::vector<std::string> cpdomains = {"9001 discuss.leetcode.com"};

    auto res = s.subdomainVisits(cpdomains);

    std::vector<std::string> exp = {"9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"};

    EXPECT_TRUE(std::is_permutation(res.begin(), res.end(), exp.begin(), exp.end()));
}
