#include "pch.h"

#include "../problems/p443.h"

TEST(p443, t0)
{
    p443::Solution s;

    std::vector<char> str = {'a', 'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    auto res = s.compress(str);
    EXPECT_EQ(res, 6);
}
