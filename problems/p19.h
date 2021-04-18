#pragma once
#include "util_linked_list.h"

namespace p19
{
    class Solution
    {
      public:
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            if (!head)
                return nullptr;

            auto* first = head;
            for (int i = 1; i <= n; ++i)
                first = first->next;

            if (!first)
                return head->next;

            auto* second = head;
            ListNode* prev_second = nullptr;
            while (first)
            {
                first = first->next;
                prev_second = second;
                second = second->next;
            }

            prev_second->next = second->next;
            return head;
        }
    };
}
