#include "pch.h"

#include "../problems/p199.h"

TEST(p199, t0)
{
    p199::Solution s;

    auto res = s.rightSideView(deserialize_tree("1(2(,5),3(,4))"));

    EXPECT_EQ(res, (std::vector<int>{1, 3, 4}));
}
