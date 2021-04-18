#include "pch.h"

#include "../problems/p341.h"

TEST(p341, t0)
{
    p341::NestedInteger n0(1);
    p341::NestedInteger n1(1);
    p341::NestedInteger n2(2);
    p341::NestedInteger n3(1);
    p341::NestedInteger n4(1);

    std::vector<p341::NestedInteger> n{p341::NestedInteger({n0, n1}), n2, p341::NestedInteger({n3, n4})};
    p341::NestedIterator i(n);

    std::vector<int> res;
    while (i.hasNext())
    {
        res.push_back(i.next());
    }

    EXPECT_EQ(res, (std::vector<int>{1, 1, 2, 1, 1}));
}
