#include "pch.h"

#include "../problems/p150.h"

TEST(p150, t0)
{
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    p150::Solution s;
    auto res = s.evalRPN(tokens);
    EXPECT_EQ(res, 9);
}
