#include "pch.h"

#include "../problems/p114.h"

TEST(p114, t0)
{
    std::string tree_str("1(2(3,4),5(,6))");
    std::string expected_str("1(,2(,3(,4(,5(,6)))))");

    p114::Solution s;
    auto* t1 = deserialize_tree(tree_str);
    s.flatten(t1);
    EXPECT_EQ(serialize_tree(t1), expected_str);

    p114::Solution2 s2;
    auto* t2 = deserialize_tree(tree_str);
    s.flatten(t2);
    EXPECT_EQ(serialize_tree(t2), expected_str);
}
