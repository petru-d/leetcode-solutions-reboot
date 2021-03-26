#include "pch.h"

#include "../problems/p1265.h"

TEST(p1265, t0)
{
    std::vector<int> accumulate_here;

    p1265::ImmutableListNode n2(2, nullptr, accumulate_here);
    p1265::ImmutableListNode n1(1, &n2, accumulate_here);
    p1265::ImmutableListNode n0(0, &n1, accumulate_here);

    p1265::Solution s;
    s.printLinkedListInReverse(&n0);

    EXPECT_EQ(accumulate_here, (std::vector<int>{2, 1, 0}));
}
