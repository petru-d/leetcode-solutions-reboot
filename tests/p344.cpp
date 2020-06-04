#include "pch.h"

#include "../problems/p344.h"

TEST(p344, t0)
{
    std::vector<char> st{'o', 'l', 'a'};
    p344::Solution s;
    s.reverseString(st);

    std::vector<char> expected = {'a', 'l', 'o'};
    ASSERT_EQ(st, expected);
}