#pragma once
#include "util_linked_list.h"

namespace p82
{
    class Solution
    {
      public:
        ListNode* deleteDuplicates(ListNode* head)
        {
            ListNode* dummy = new ListNode();
            dummy->next = head;

            auto* curr = dummy;
            while (curr)
            {
                if (!curr->next || !curr->next->next)
                    break;

                if (curr->next->val != curr->next->next->val)
                    curr = curr->next;
                else
                {
                    auto* dup = curr->next->next;
                    while (dup && dup->val == curr->next->val)
                        dup = dup->next;
                    curr->next = dup;
                }
            }

            return dummy->next;
        }
    };
}
