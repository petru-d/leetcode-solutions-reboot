#include "pch.h"

#include "../problems/p752.h"

TEST(p752, t0)
{
    p752::Solution s;

    std::vector<std::string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    std::string target = "0202";

    auto res = s.openLock(deadends, target);

    EXPECT_EQ(res, 6);
}
