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

    class Solution2
    {
      public:
        ListNode* partition(ListNode* head, int x)
        {
            ListNode* small = nullptr;
            ListNode* small_tail = nullptr;

            ListNode* big = nullptr;
            ListNode* big_tail = nullptr;

            auto move_to_list = [](ListNode*& head, ListNode*& tail, ListNode* n) {
                if (!tail)
                    head = tail = n;
                else
                {
                    tail->next = n;
                    tail = n;
                }
            };

            ListNode* curr = head;
            while (curr)
            {
                if (curr->val < x)
                    move_to_list(small, small_tail, curr);
                else
                    move_to_list(big, big_tail, curr);

                curr = curr->next;
            }

            if (big_tail)
                big_tail->next = nullptr;

            if (!small_tail)
                return big;

            small_tail->next = big;
            return small;
        }
    };
}
