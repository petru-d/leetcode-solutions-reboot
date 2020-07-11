#include "pch.h"

#include "../problems/p430.h"

TEST(p430, t0)
{
    p430::Solution s;

    p430::Node n1{1, nullptr, nullptr, nullptr};
    p430::Node n2{1, nullptr, nullptr, nullptr};
    p430::Node n3{1, nullptr, nullptr, nullptr};

    n1.next = &n2;
    n2.prev = &n1;
    n1.child = &n3;

    auto* res = s.flatten(&n1);

    ASSERT_TRUE(res != nullptr);

    EXPECT_EQ(res->val, 1);
}
