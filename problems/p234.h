#pragma once
#include "util_linked_list.h"

namespace p234
{
    class Solution
    {
      public:
        bool isPalindrome(ListNode* head)
        {
            if (!head)
                return true;

            size_t count = 1;

            // find mid
            // - for odd length lists it will be exactly in the middle
            // - for even length lists it will be the "second" middle
            auto* mid = head;
            auto* fast = head;
            while (fast)
            {
                fast = fast->next;
                if (!fast)
                    break;
                ++count;
                fast = fast->next;
                if (fast)
                    ++count;
                mid = mid->next;
            }

            // reverse secod half
            auto* curr = mid;
            auto* next = mid->next;
            mid->next = nullptr;
            while (next)
            {
                auto* next_next = next->next;
                next->next = curr;
                curr = next;
                next = next_next;
            }
            auto* other_head = curr;

            // compare
            // dividing odd count by 2 will not include the "true middle" for odd length lists,
            // which is exactly what we want
            for (size_t i = 1; i <= count / 2; ++i)
            {
                if (head->val != other_head->val)
                    return false;
                head = head->next;
                other_head = other_head->next;
            }

            return true;
        }
    };
}
