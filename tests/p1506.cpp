#include "pch.h"

#include "../problems/p1506.h"

TEST(p1506, t0)
{
    p1506::Solution s;

    p1506::Node tree(10);

    auto* r = s.findRoot({&tree});

    ASSERT_TRUE(r != nullptr);

    EXPECT_EQ(r->val, 10);
}
