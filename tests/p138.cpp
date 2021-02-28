#include "pch.h"

#include "../problems/p138.h"

TEST(p138, t0)
{
    p138::Solution s;

    auto n7 = p138::Node(7);
    auto n13 = p138::Node(13);
    auto n11 = p138::Node(11);
    auto n10 = p138::Node(10);
    auto n1 = p138::Node(1);

    n7.next = &n13;
    n13.next = &n11;
    n11.next = &n10;
    n10.next = &n1;

    n13.random = &n7;
    n11.random = &n1;
    n10.random = &n11;
    n1.random = &n7;

    auto* c = s.copyRandomList(&n7);

    ASSERT_TRUE(c != nullptr);
    EXPECT_EQ(c->val, 7);
}
