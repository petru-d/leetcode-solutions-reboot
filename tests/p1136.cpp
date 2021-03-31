#include "pch.h"

#include "../problems/p1136.h"

TEST(p1136, t0)
{

    std::vector<std::vector<int>> c{{1, 3}, {2, 3}};

    p1136::Solution s;
    auto res = s.minimumSemesters(3, c);
    EXPECT_EQ(res, 2);

    p1136::Solution2 s2;
    res = s2.minimumSemesters(3, c);
    EXPECT_EQ(res, 2);
}
