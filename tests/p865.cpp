#include "pch.h"

#include "../problems/p865.h"

TEST(p865, t0)
{
    auto* t2 = make_binary_tree(7, 2, 4);
    auto* t6 = make_binary_tree(6);
    auto* t5 = make_binary_tree(t6, 5, t2);
    auto* t1 = make_binary_tree(0, 1, 8);
    auto* t3 = make_binary_tree(t5, 3, t1);

    p865::Solution s;

    auto* result = s.subtreeWithAllDeepest(t3);

    auto result_vec = to_vector_levelwise_full(result);
    std::vector<std::optional<int>> expected_vec = {2, 7, 4};

    EXPECT_EQ(result_vec, expected_vec);
}
