#include "pch.h"

#include "../problems/p468.h"

TEST(p468, t0)
{
    p468::Solution s;

    auto res = s.validIPAddress("172.16.254.1");
    EXPECT_EQ(res, "IPv4");
}
