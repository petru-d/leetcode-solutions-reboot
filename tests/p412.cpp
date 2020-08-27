#include "pch.h"

#include "../problems/p412.h"

TEST(p412, t0)
{
    p412::Solution s;

    auto res = s.fizzBuzz(15);
    ASSERT_TRUE(res.size() == 15);
    EXPECT_EQ(res[0], "1");
    EXPECT_EQ(res[2], "Fizz");
    EXPECT_EQ(res[4], "Buzz");
    EXPECT_EQ(res[14], "FizzBuzz");
}
