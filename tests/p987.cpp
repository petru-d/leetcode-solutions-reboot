#include "pch.h"

#include "../problems/p987.h"

TEST(p987, t0)
{
    p987::Solution s;

    auto* tree = deserialize_tree("3(9,20(15,7))");
    auto res = s.verticalTraversal(tree);

    std::vector<std::vector<int>> expected = {{9}, {3, 15}, {20}, {7}};

    EXPECT_EQ(res, expected);
}
