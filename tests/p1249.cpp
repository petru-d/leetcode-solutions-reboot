#include "pch.h"

#include "../problems/p1249.h"

TEST(p1249, t0)
{
    p1249::Solution s;
    auto res = s.minRemoveToMakeValid("lee(t(c)o)de)");

    EXPECT_TRUE(res == "lee(t(co)de)" || res == "lee(t(c)ode)" || res == "lee(t(c)o)de");
}
