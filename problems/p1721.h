#pragma once
#include "util_linked_list.h"

namespace p1721
{
    class Solution
    {
      public:
        ListNode* swapNodes(ListNode* head, int k)
        {
            auto* k_from_head = head;
            for (int i = 1; i < k; ++i)
                k_from_head = k_from_head->next;

            auto* k_from_tail = head;
            auto* reaches_end = k_from_head->next;
            while (reaches_end)
            {
                k_from_tail = k_from_tail->next;
                reaches_end = reaches_end->next;
            }

            std::swap(k_from_head->val, k_from_tail->val);

            return head;
        }
    };
}
