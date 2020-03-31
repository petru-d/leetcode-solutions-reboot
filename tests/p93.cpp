#include "pch.h"

#include "../problems/p93.h"

TEST(P93, T0)
{
    p93::Solution s;
    auto result = s.restoreIpAddresses("25525511135");

    std::vector<string> expected = {"255.255.11.135", "255.255.111.35"};
    EXPECT_EQ(result, expected);
}

TEST(P93, T1)
{

    p93::Solution s;
    auto result = s.restoreIpAddresses("255255255255");

    std::vector<string> expected = {"255.255.255.255"};
    EXPECT_EQ(result, expected);
}

TEST(P93, T2)
{

    p93::Solution s;
    auto result = s.restoreIpAddresses("0000");

    std::vector<string> expected = {"0.0.0.0"};
    EXPECT_EQ(result, expected);
}

TEST(P93, T3)
{

    p93::Solution s;
    auto result = s.restoreIpAddresses("1111");

    std::vector<string> expected = {"1.1.1.1"};
    EXPECT_EQ(result, expected);
}

TEST(P93, T4)
{

    p93::Solution s;
    auto result = s.restoreIpAddresses("11111");

    std::vector<string> expected = {"1.1.1.11", "1.1.11.1", "1.11.1.1", "11.1.1.1"};
    EXPECT_EQ(result, expected);
}

TEST(P93, T5)
{

    p93::Solution s;
    auto result = s.restoreIpAddresses("010010");

    std::vector<string> expected = {"0.10.0.10", "0.100.1.0"};

    EXPECT_EQ(result, expected);
}
