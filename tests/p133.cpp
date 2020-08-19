#include "pch.h"

#include "../problems/p133.h"

TEST(p133, t0)
{
    p133::Solution s;

    auto* n1 = new p133::Node(1);
    auto* n2 = new p133::Node(2);
    auto* n3 = new p133::Node(3);
    auto* n4 = new p133::Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    auto* nn1 = s.cloneGraph(n1);
    ASSERT_TRUE(nn1 != nullptr);
}
