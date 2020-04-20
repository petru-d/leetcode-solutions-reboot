#include "pch.h"

#include "../problems/p1008.h"

TEST(p1008, t0)
{

    p1008::Solution s;
    std::vector<int> preorder = {8, 5, 1, 7, 10, 12};
    auto* tree = s.bstFromPreorder(preorder);

    auto result = to_vector_levelwise_full(tree);
    std::vector<std::optional<int>> expected = {8, 5, 10, 1, 7, {}, 12};
    EXPECT_EQ(result, expected);
}
