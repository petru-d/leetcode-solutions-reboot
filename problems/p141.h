#pragma once
#include "util_linked_list.h"

namespace p141
{
    class Solution
    {
      public:
        bool hasCycle(ListNode* head)
        {
            if (!head)
                return false;
            auto* fast = head;
            auto* slow = head;

            while (true)
            {
                fast = fast->next;
                if (!fast)
                    return false;
                fast = fast->next;
                if (!fast)
                    return false;
                slow = slow->next;

                if (fast == slow)
                    return true;
            }

            assert(false);
            return false;
        }
    };
}
