#include "pch.h"

#include "../problems/p61.h"

p61::ListNode* make_list(const std::vector<int>& data)
{
    if (data.empty())
        return nullptr;

    auto* head = new p61::ListNode(data.front());
    auto* curr = head;
    for (size_t i = 1; i < data.size(); ++i)
    {
        auto* next = new p61::ListNode(data[i]);
        curr->next = next;
        curr = next;
    }

    return head;
}

bool eq_lists(const p61::ListNode* left, const p61::ListNode* right)
{
    auto* curr_l = left;
    auto* curr_r = right;

    while (curr_l != nullptr && curr_r != nullptr)
    {
        if (curr_l->val != curr_r->val)
            return false;

        curr_l = curr_l->next;
        curr_r = curr_r->next;
    }

    // at least one curr is nullptr here. the lists are equal iff both currs are nullptr
    return curr_l == curr_r;
}

TEST(P61, T0)
{
    p61::Solution s;

    auto* result = s.rotateRight(make_list({1, 2, 3, 4, 5}), 2);
    auto* expected = make_list({4, 5, 1, 2, 3});

    EXPECT_EQ(true, eq_lists(result, expected));
}

TEST(P61, T1)
{
    p61::Solution s;

    auto* result = s.rotateRight(make_list({0, 1, 2}), 4);
    auto* expected = make_list({2, 0, 1});

    EXPECT_EQ(true, eq_lists(result, expected));
}
