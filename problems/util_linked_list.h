#pragma once
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

inline ListNode* make_list(const std::vector<int>& data)
{
    if (data.empty())
        return nullptr;

    auto* head = new ListNode(data.front());
    auto* curr = head;
    for (size_t i = 1; i < data.size(); ++i)
    {
        auto* next = new ListNode(data[i]);
        curr->next = next;
        curr = next;
    }

    return head;
}

inline bool eq_lists(const ListNode* left, const ListNode* right)
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