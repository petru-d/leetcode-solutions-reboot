#include "pch.h"

#include "../problems/p1673.h"

TEST(p1673, t0)
{
    p1673::Solution s;

    std::vector<int> seq = {3, 5, 2, 6};
    auto res = s.mostCompetitive(seq, 2);

    EXPECT_EQ(res, std::vector<int>({2, 6}));
}
