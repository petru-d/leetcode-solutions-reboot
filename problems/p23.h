#pragma once
#include "util_linked_list.h"
#include <queue>
#include <vector>

namespace p23
{
    class Solution
    {
      public:
        ListNode* mergeKLists(std::vector<ListNode*>& lists)
        {
            auto cmp = [](const ListNode* l, const ListNode* r) { return l->val > r->val; };

            ListNode* merged = new ListNode();
            ListNode* curr_merged = merged;
            auto append = [&](ListNode* n) {
                curr_merged->next = n;
                curr_merged = n;
            };

            std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> q(cmp);

            for (auto* n : lists)
                if (n)
                    q.push(n);

            while (!q.empty())
            {
                auto* t = q.top();
                append(t);
                q.pop();
                if (t->next)
                    q.push(t->next);
            }

            return merged->next;
        }
    };
}
