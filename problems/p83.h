#pragma once
#include "util_linked_list.h"

namespace p83
{
    class Solution
    {
      public:
        ListNode* deleteDuplicates2(ListNode* head)
        {
            if (nullptr == head)
                return nullptr;

            auto* seg_start = head;
            while (seg_start != nullptr)
            {
                auto* curr_seg = seg_start;
                auto v = seg_start->val;
                while (nullptr != curr_seg && curr_seg->val == v)
                {
                    curr_seg = curr_seg->next;
                }
                // leak all the removed objects like an animal
                seg_start->next = curr_seg;
                seg_start = seg_start->next;
            }
            return head;
        }

        ListNode* deleteDuplicates(ListNode* head)
        {
            if (nullptr == head || nullptr == head->next)
                return head;

            auto* curr = head;

            while (curr && curr->next)
            {
                while (curr->next && curr->val != curr->next->val)
                {
                    curr = curr->next;
                    if (!curr || !curr->next)
                        return head;
                }
                curr->next = curr->next->next;
            }

            return head;
        }
    };
}