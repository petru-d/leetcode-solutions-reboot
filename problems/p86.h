#pragma once
#include "util_linked_list.h"

namespace p86
{
    class Solution
    {
      public:
        ListNode* partition(ListNode* head, int x)
        {
            auto to_list = [](ListNode*& head, ListNode*& tail, ListNode* node) {
                if (nullptr == head && nullptr == tail)
                {
                    head = tail = node;
                    node->next = nullptr;
                }
                else
                {
                    tail->next = node;
                    node->next = nullptr;
                    tail = node;
                }
            };

            ListNode* head_smaller = nullptr;
            ListNode* tail_smaller = nullptr;
            ListNode* head_bigger_eq = nullptr;
            ListNode* tail_bigger_eq = nullptr;

            ListNode* curr = head;
            while (curr)
            {
                auto* next = curr->next;
                if (curr->val >= x)
                    to_list(head_bigger_eq, tail_bigger_eq, curr);
                else
                    to_list(head_smaller, tail_smaller, curr);

                curr = next;
            }

            if (!head_smaller)
                return head_bigger_eq;
            if (!head_bigger_eq)
                return head_smaller;

            tail_smaller->next = head_bigger_eq;
            return head_smaller;
        }
    };
}
