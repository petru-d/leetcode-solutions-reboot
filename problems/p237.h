#pragma once

#include "util_linked_list.h"

namespace p237
{
    class Solution
    {
      public:
        void deleteNode(ListNode* node)
        {
            node->val = node->next->val;

            auto* prev = node;
            auto* curr = node->next;

            while (curr)
            {
                if (!curr->next)
                {
                    delete curr;
                    prev->next = nullptr;
                    return;
                }
                curr->val = curr->next->val;
                prev = curr;
                curr = curr->next;
            }
        }
    };
}