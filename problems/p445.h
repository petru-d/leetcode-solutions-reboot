#pragma once
#include "util_linked_list.h"
#include <stack>

namespace p445
{
    class Solution
    {
      public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            auto make_stack = [](ListNode* l) {
                std::stack<int> res;

                while (l != nullptr)
                {
                    res.push(l->val);
                    l = l->next;
                }
                return res;
            };

            auto first = make_stack(l1);
            auto second = make_stack(l2);

            if (first.size() < second.size())
                std::swap(first, second);

            ListNode* result = nullptr;
            auto push_node = [&result](auto val) {
                auto* new_node = new ListNode(val);
                new_node->next = result;
                result = new_node;
            };

            int rem = 0;
            while (!first.empty())
            {
                auto [new_rem, new_val] = std::div(first.top() + (second.empty() ? 0 : second.top()) + rem, 10);
                rem = new_rem;

                push_node(new_val);

                first.pop();
                if (!second.empty())
                    second.pop();
            }

            if (rem != 0)
                push_node(rem);

            return result;
        }
    };
}
