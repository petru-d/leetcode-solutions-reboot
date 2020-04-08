#pragma once
#include "util_linked_list.h"
#include <array>

namespace p876
{

    // alternative (better) solution: use two pointers, fast and slow. Fast is 2x faster than slow. When fast reaches end, slow is
    // where we need it to be.

    class Solution
    {
      public:
        ListNode* middleNode(ListNode* head)
        {
            std::array<ListNode*, 100> cache;

            size_t index = -1;
            while (nullptr != head)
            {
                cache[++index] = head;
                head = head->next;
            }

            return cache[(index + 1) / 2];
        }
    };
}