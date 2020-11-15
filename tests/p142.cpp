#include "pch.h"

#include "../problems/p142.h"

TEST(p142, t0)
{
    p142::Solution s;

    auto* head = make_list({3, 2, 0, 4});
    head->next->next->next = head->next;

    auto* c = s.detectCycle(head);
    ASSERT_NE(c, nullptr);

    EXPECT_EQ(c->val, 2);
}
