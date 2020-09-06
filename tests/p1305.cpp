#include "pch.h"

#include "../problems/p1305.h"

TEST(p1305, t0)
{
    auto* t1 = deserialize_tree("2(1,4)");
    auto* t2 = deserialize_tree("1(0,3)");

    p1305::Solution s;
    auto res = s.getAllElements(t1, t2);

    std::vector<int> expected = {0, 1, 1, 2, 3, 4};
    EXPECT_EQ(res, expected);
}
