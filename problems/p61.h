#pragma once

namespace p61
{
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr)
        {
        }
    };

    class Solution
    {
      public:
        ListNode* rotateRight(ListNode* head, int k)
        {
            if (nullptr == head)
                return nullptr;

            // make it circular, keep the element count
            size_t count = 1;
            auto* curr = head;
            while (curr->next != nullptr)
            {
                curr = curr->next;
                ++count;
            }
            curr->next = head;

            // if rotating left, the offset would have been k % count, so rotating right:
            size_t offset = count - k % count;

            // offset head and de-circularize the list just before the new head
            for (size_t i = 0; i < offset - 1; ++i)
                head = head->next;
            auto* next_head = head->next;
            head->next = nullptr;

            return next_head;
        }
    };
}