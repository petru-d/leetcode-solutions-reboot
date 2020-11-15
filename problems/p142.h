#pragma once
#include "util_linked_list.h"

namespace p142
{
    class Solution
    {
      public:
        ListNode* detectCycle(ListNode* head)
        {
            auto* slow = head;
            auto* fast = head;
            if (fast == nullptr)
                return nullptr;

            while (true)
            {
                slow = slow->next;
                fast = fast->next;
                if (fast == nullptr)
                    return nullptr;
                fast = fast->next;
                if (fast == nullptr)
                    return nullptr;
                if (slow == fast)
                    break;
            }

            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    };
}
