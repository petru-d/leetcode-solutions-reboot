#pragma once
#include "util_linked_list.h"

namespace p24
{
    class Solution
    {
      public:
        ListNode* swapPairs(ListNode* head)
        {
            if (!head || !head->next)
                return head;

            auto* dummy = new ListNode(0, head);

            auto* l = dummy;
            auto* r = dummy->next->next->next;

            auto swapnodes = [](ListNode* l, ListNode* r) {
                auto* n1 = l->next;
                auto* n2 = l->next->next;

                l->next = n2;
                n2->next = n1;
                n1->next = r;
            };

            while (l && l->next && l->next->next)
            {
                swapnodes(l, l->next->next->next);
                l = l->next->next;
            }

            return dummy->next;
        }
    };
}
