#pragma once
#include "util_linked_list.h"

namespace p147
{
    class Solution
    {
      public:
        ListNode* insertionSortList(ListNode* head)
        {
            if (nullptr == head)
                return nullptr;

            auto* dummy_head = new ListNode(std::numeric_limits<int>::min());
            dummy_head->next = head;

            auto* curr = head->next;
            auto* end_sorted = head;

            while (curr != nullptr)
            {
                auto* first = dummy_head;
                auto* second = dummy_head->next;

                while (first != end_sorted)
                {
                    if (first->val <= curr->val && curr->val <= second->val)
                    {
                        end_sorted->next = curr->next;
                        first->next = curr;
                        curr->next = second;

                        break;
                    }
                    first = first->next;
                    second = second->next;
                }

                if (first == end_sorted)
                {
                    end_sorted = curr;
                    curr = curr->next;
                }
                else
                {
                    curr = end_sorted->next;
                }
            }

            return dummy_head->next;
        }
    };
}
