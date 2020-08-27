#include "pch.h"

#include "../problems/p497.h"

TEST(p497, t0)
{
    std::vector<std::vector<int>> rects = {{1, 1, 5, 5}};
    p497::Solution s(rects);

    auto r1 = s.pick();

    ASSERT_TRUE(r1.size() == 2);

    EXPECT_TRUE(r1[0] >= 1 && r1[0] <= 5);
    EXPECT_TRUE(r1[1] >= 1 && r1[1] <= 5);
}
