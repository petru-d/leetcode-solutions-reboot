#include "pch.h"

#include "../problems/p606.h"

TEST(p606, t0)
{
    auto* t = deserialize_tree("1(2(4,),3)");
    p606::Solution s;

    auto res = s.tree2str(t);

    EXPECT_EQ(res, "1(2(4))(3)");
}
