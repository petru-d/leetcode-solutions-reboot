#pragma once

#include "util_linked_list.h"

namespace p143
{

    class Solution
    {
      public:
        void reorderList(ListNode* head)
        {
            if (nullptr == head || nullptr == head->next)
                return;

            // find middle and number N of elements after it - last element from the reordered list
            // (slow/fast pointers)
            auto* slow = head;
            auto* fast = head;
            ListNode* tail = nullptr;
            size_t count = 0;
            while (true)
            {
                if (fast->next == nullptr)
                {
                    tail = fast;
                    break;
                }
                if (fast->next->next == nullptr)
                {
                    ++count;
                    tail = fast->next;
                    break;
                }
                ++count;
                slow = slow->next;
                fast = fast->next->next;
            }

            // reverse the sublist starting at middle->next
            // start with pointer to head = middle->next and tail
            // N - 1 times: move head after tail, update head but not tail
            for (size_t i = 0; i < count - 1; ++i)
            {
                auto* n = slow->next;
                slow->next = n->next;

                auto* tnext = tail->next;
                tail->next = n;
                n->next = tnext;
            }

            // splice the reversed sublist in the first part of the initial list
            auto* insert_point = head;
            for (size_t i = 0; i < count; ++i)
            {
                auto* n = slow->next;
                auto* n_next = n->next;
                slow->next = n_next;

                auto* insert_point_next = insert_point->next;
                insert_point->next = n;
                n->next = insert_point_next;

                insert_point = insert_point->next->next;
            }
        }
    };
}
