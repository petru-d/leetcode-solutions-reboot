#include "pch.h"

#include "../problems/p86.h"

TEST(p86, t0)
{
    auto* head = make_list({1, 4, 3, 2, 5, 2});
    auto* expected = make_list({1, 2, 2, 4, 3, 5});

    p86::Solution s;
    head = s.partition(head, 3);
    EXPECT_TRUE(eq_lists(head, expected));

    p86::Solution2 s2;
    head = s2.partition(head, 3);
    EXPECT_TRUE(eq_lists(head, expected));
}
