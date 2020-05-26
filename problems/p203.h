#pragma once
#include "util_linked_list.h"

namespace p203
{
    class Solution
    {
      public:
        ListNode* removeElements(ListNode* head, int val)
        {
            auto* dummy = new ListNode(0);
            dummy->next = head;

            auto* curr = dummy->next;
            auto* prev = dummy;
            while (curr != nullptr)
            {
                if (curr->val == val)
                {
                    prev->next = curr->next;
                    auto* next_curr = curr->next;
                    delete curr;
                    curr = next_curr;
                }
                else
                {
                    prev = prev->next;
                    curr = curr->next;
                }
            }

            head = dummy->next;
            delete dummy;

            return head;
        }
    };
}