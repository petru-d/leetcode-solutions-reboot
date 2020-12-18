#pragma once
#include "util_linked_list.h"
#include <stack>

namespace p369
{
    class Solution
    {
      public:
        ListNode* plusOne(ListNode* head)
        {
            std::stack<ListNode*> list;
            auto* curr = head;
            while (curr)
            {
                list.push(curr);
                curr = curr->next;
            }

            int oneOver = 1;
            while (!list.empty())
            {
                auto* curr = list.top();
                list.pop();

                auto [q, r] = std::div(oneOver + curr->val, 10);
                curr->val = r;
                oneOver = q;
                if (0 == oneOver)
                    break;
            }

            if (oneOver == 1)
            {
                auto* oneNode = new ListNode(1);
                oneNode->next = head;
                head = oneNode;
            }

            return head;
        }
    };

}
