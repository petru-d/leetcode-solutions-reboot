#include "pch.h"

#include "../problems/p1662.h"

TEST(p1662, t0)
{
    p1662::Solution s;
    std::vector<std::string> w1 = {"ab", "c"};
    std::vector<std::string> w2 = {"a", "bc"};

    auto res = s.arrayStringsAreEqual(w1, w2);

    EXPECT_TRUE(res);
}
