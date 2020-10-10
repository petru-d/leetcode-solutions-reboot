#include "pch.h"

#include "../problems/p1598.h"

TEST(p1598, t0)
{
    p1598::Solution s;

    std::vector<std::string> logs = {"d1/", "d2/", "../", "d21/", "./"};

    auto res = s.minOperations(logs);

    EXPECT_EQ(res, 2);
}
