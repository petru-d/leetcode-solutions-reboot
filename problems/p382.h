#pragma once
#include "util_linked_list.h"
#include <random>

namespace p382
{
    class Solution
    {
      public:
        /** @param head The linked list's head.
            Note that the head is guaranteed to be not null, so it contains at least one node. */
        Solution(ListNode* head)
        {
            _head = head;

            std::random_device rd;
            _gen = std::mt19937(rd());

            int len = 0;
            while (head)
            {
                ++len;
                head = head->next;
            }

            _distrib = std::uniform_int_distribution<>(0, len - 1);
        }

        /** Returns a random node's value. */
        int getRandom()
        {
            int advance = _distrib(_gen);

            auto* curr = _head;
            for (int i = 0; i < advance; ++i)
            {
                curr = curr->next;
            }

            return curr->val;
        }

      private:
        ListNode* _head;
        std::mt19937 _gen;
        std::uniform_int_distribution<> _distrib;
    };
}
