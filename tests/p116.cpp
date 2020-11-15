#include "pch.h"

#include "../problems/p116.h"

TEST(p116, t0)
{
    p116::Solution s;

    p116::Node n1(1);
    p116::Node n2(2);
    p116::Node n3(3);
    p116::Node n4(4);
    p116::Node n5(5);
    p116::Node n6(6);
    p116::Node n7(7);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    s.connect(&n1);

    EXPECT_EQ(n2.next, &n3);
}
