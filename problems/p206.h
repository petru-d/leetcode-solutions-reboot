#pragma once

#include "util_linked_list.h"

namespace p206
{
    class Solution
    {
      public:
        ListNode* reverseList_iterative(ListNode* head)
        {
            ListNode* new_head = nullptr;
            auto* curr = head;
            while (curr != nullptr)
            {
                auto* n = curr->next;
                curr->next = new_head;
                new_head = curr;

                curr = n;
            }

            return new_head;
        }

        ListNode* reverseList(ListNode* head)
        {

            return reverse(head).first;
        }

        std::pair<ListNode*, ListNode*> reverse(ListNode* n)
        {
            if (n == nullptr)
                return {nullptr, nullptr};

            if (n->next == nullptr)
                return {n, n};

            auto [head, tail] = reverse(n->next);
            tail->next = n;
            n->next = nullptr;
            return {head, n};
        }
    };
}
