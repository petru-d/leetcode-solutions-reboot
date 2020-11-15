#include "pch.h"

#include "../problems/p832.h"

TEST(p832, t0)
{
    p832::Solution s;
    std::vector<std::vector<int>> i = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};

    auto res = s.flipAndInvertImage(i);
    
    EXPECT_EQ(res, std::vector<std::vector<int>>({{1, 0, 0}, {0, 1, 0}, {1, 1, 1}}));
}
