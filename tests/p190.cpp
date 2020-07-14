#include "pch.h"

#include "../problems/p190.h"

TEST(p190, t0)
{
    p190::Solution s;
    auto res = s.reverseBits(0b00000010100101000001111010011100);

    EXPECT_EQ(res, 0b00111001011110000010100101000000);
}

TEST(p190, t1)
{
    p190::Solution s;
    auto res = s.reverseBits(0b00000000000000000000000000001000);

    EXPECT_EQ(res, 0b00010000000000000000000000000000);
}

TEST(p190, t2)
{
    p190::Solution s;
    s.print_reverser();
}
