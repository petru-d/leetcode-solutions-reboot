#include "pch.h"

#include "../problems/p744.h"

TEST(p744, t0)
{
    p744::Solution s;

    std::vector<char> letters = {'c', 'f', 'j'};

    auto res = s.nextGreatestLetter(letters, 'a');

    EXPECT_EQ(res, 'c');
}
