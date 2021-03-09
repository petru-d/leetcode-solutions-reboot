#include "pch.h"

#include "../problems/p623.h"

TEST(p623, t0)
{
    p623::Solution s;
    auto res = s.addOneRow(deserialize_tree("4(2(3,1),6(5,))"), 1, 2);

    EXPECT_EQ(serialize_tree(res), "4(1(2(3,1),),1(,6(5,)))");
}
