#pragma once

namespace p430
{
    class Node
    {
      public:
        int val;
        Node* prev;
        Node* next;
        Node* child;
    };

    class Solution
    {
      public:
        Node* flatten(Node* head)
        {
            if (nullptr == head)
                return nullptr;

            flatten_rec(head);
            return head;
        }

        // returns the tail of the flattened list
        Node* flatten_rec(Node* head)
        {
            auto* curr = head;
            while (curr != nullptr)
            {
                if (!curr->child)
                {
                    if (curr->next == nullptr)
                        return curr;
                    curr = curr->next;
                    continue;
                }

                auto* flat_end = flatten_rec(curr->child);

                auto* next = curr->next;

                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;

                flat_end->next = next;
                if (next != nullptr)
                {
                    next->prev = flat_end;
                }

                if (next == nullptr)
                    return flat_end;
                curr = next;
            }

            return nullptr;
        }
    };
}
