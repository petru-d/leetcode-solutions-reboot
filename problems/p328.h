#pragma once
#include "util_linked_list.h"

namespace p328
{
    class Solution
    {
      public:
        ListNode* oddEvenList(ListNode* head)
        {
            if (!head || !head->next)
                return head;

            // auto* headOdd = head;
            auto* tailOdd = head;
            auto* headEven = head->next;
            auto* tailEven = head->next;
            auto* curr = head->next->next;

            bool odd = true;
            while (curr)
            {
                if (odd)
                {
                    tailOdd->next = curr;
                    tailOdd = curr;
                }
                else
                {
                    tailEven->next = curr;
                    tailEven = curr;
                }
                odd = !odd;
                curr = curr->next;
            }
            tailOdd->next = headEven;
            tailEven->next = nullptr;

            return head;
        }
    };
}