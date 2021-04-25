#include "pch.h"

#include "../problems/p589.h"

TEST(p589, t0)
{
    p589::Node root(1);

    p589::Node l10(3);
    p589::Node l11(2);
    p589::Node l12(4);

    root.children = {&l10, &l11, &l12};

    p589::Solution s;
    auto res = s.preorder(&root);
    EXPECT_EQ(res, (std::vector<int>{1, 3, 2, 4}));

    p589::Solution2 s2;
    auto res2 = s2.preorder(&root);
    EXPECT_EQ(res2, (std::vector<int>{1, 3, 2, 4}));
}
