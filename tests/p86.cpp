#include "pch.h"

#include "../problems/p86.h"

TEST(p86, t0)
{
    p86::Solution s;

    auto* head = make_list({1, 4, 3, 2, 5, 2});
    head = s.partition(head, 3);

    auto* expected = make_list({1, 2, 2, 4, 3, 5});

    EXPECT_TRUE(eq_lists(head, expected));
}
