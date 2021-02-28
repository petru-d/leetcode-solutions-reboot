#pragma once
#include <unordered_map>

namespace p138
{
    // Definition for a Node.
    class Node
    {
      public:
        int val;
        Node* next;
        Node* random;

        Node(int _val)
        {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
    };

    class Solution
    {
      public:
        Node* copyRandomList(Node* head)
        {
            if (!head)
                return nullptr;

            std::unordered_map<Node*, Node*> new_to_old;
            std::unordered_map<size_t, Node*> index_to_new;
            std::unordered_map<Node*, size_t> old_to_index;

            auto* new_head = new Node(head->val);
            new_to_old[new_head] = head;
            index_to_new[0] = new_head;
            old_to_index[head] = 0;
            size_t i = 0;
            auto* new_tail = new_head;
            auto* curr = head->next;
            while (curr)
            {
                ++i;
                auto* n = new Node(curr->val);
                new_tail->next = n;
                new_tail = n;

                new_to_old[n] = curr;
                index_to_new[i] = n;
                old_to_index[curr] = i;

                curr = curr->next;
            }

            curr = head;
            auto* new_curr = new_head;
            while (curr)
            {
                auto* rand = curr->random;
                if (rand != nullptr)
                {
                    auto index = old_to_index[rand];
                    auto* new_random = index_to_new[index];

                    new_curr->random = new_random;
                }
                curr = curr->next;
                new_curr = new_curr->next;
            }

            return new_head;
        }
    };

}
