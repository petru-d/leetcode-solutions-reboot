#include "pch.h"

#include "../problems/p284.h"

TEST(p284, t0)
{
    std::vector<int> nums = {1, 2, 3};
    p284::PeekingIterator p(nums);

    auto res = p.next();
    EXPECT_EQ(res, 1);

    res = p.peek();
    EXPECT_EQ(res, 2);

    res = p.next();
    EXPECT_EQ(res, 2);

    res = p.next();
    EXPECT_EQ(res, 3);

    auto nex = p.hasNext();
    EXPECT_FALSE(nex);
}
