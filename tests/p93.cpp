#include "pch.h"

#include "../problems/p93.h"

TEST(p93, t0)
{
    p93::Solution s;
    auto result = s.restoreIpAddresses("25525511135");

    std::vector<std::string> expected = {"255.255.11.135", "255.255.111.35"};
    EXPECT_EQ(result, expected);
}

TEST(p93, t1)
{

    p93::Solution s;
    auto result = s.restoreIpAddresses("255255255255");

    std::vector<std::string> expected = {"255.255.255.255"};
    EXPECT_EQ(result, expected);
}

TEST(p93, t2)
{

    p93::Solution s;
    auto result = s.restoreIpAddresses("0000");

    std::vector<std::string> expected = {"0.0.0.0"};
    EXPECT_EQ(result, expected);
}

TEST(p93, t3)
{

    p93::Solution s;
    auto result = s.restoreIpAddresses("1111");

    std::vector<std::string> expected = {"1.1.1.1"};
    EXPECT_EQ(result, expected);
}

TEST(p93, t4)
{

    p93::Solution s;
    auto result = s.restoreIpAddresses("11111");

    std::vector<std::string> expected = {"1.1.1.11", "1.1.11.1", "1.11.1.1", "11.1.1.1"};
    EXPECT_EQ(result, expected);
}

TEST(p93, t5)
{

    p93::Solution s;
    auto result = s.restoreIpAddresses("010010");

    std::vector<std::string> expected = {"0.10.0.10", "0.100.1.0"};

    EXPECT_EQ(result, expected);
}
