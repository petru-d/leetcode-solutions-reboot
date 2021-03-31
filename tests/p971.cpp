#include "pch.h"

#include "../problems/p971.h"

TEST(p971, t0)
{
    auto tree = deserialize_tree("1(2,)");
    std::vector<int> voyage = {2, 1};

    p971::Solution s;
    auto res = s.flipMatchVoyage(tree, voyage);
    EXPECT_EQ(res, (std::vector<int>{-1}));

    p971::Solution2 s2;
    res = s2.flipMatchVoyage(tree, voyage);
    EXPECT_EQ(res, (std::vector<int>{-1}));
}
