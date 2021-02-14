#include "pch.h"

#include "../problems/p339.h"

TEST(p339, t0)
{
    p339::Solution s;

    p339::NestedInteger first;
    first.add(p339::NestedInteger(1));
    first.add(p339::NestedInteger(1));

    p339::NestedInteger second(2);

    p339::NestedInteger third;
    third.add(p339::NestedInteger(1));
    third.add(p339::NestedInteger(1));

    std::vector<p339::NestedInteger> l = {first, second, third};

    auto res = s.depthSum(l);

    EXPECT_EQ(res, 10);
}
