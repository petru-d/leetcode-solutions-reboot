#include "pch.h"

#include "../problems/p535.h"

TEST(p535, t0)
{
    p535::Solution s;

    auto res = s.decode(s.encode("Aaaa"));
    EXPECT_EQ(res, "Aaaa");
}
