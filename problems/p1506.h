#pragma once
#include <vector>

namespace p1506
{
    class Node
    {
      public:
        int val = 0;
        std::vector<Node*> children;

        Node()
        {
        }

        Node(int _val)
        {
            val = _val;
        }

        Node(int _val, std::vector<Node*> _children)
        {
            val = _val;
            children = _children;
        }
    };
    class Solution
    {
      public:
        Node* findRoot(std::vector<Node*> tree)
        {
            // all even
            for (auto* n : tree)
            {
                n->val *= 2;
            }

            // all odd (except the root)
            for (auto* n : tree)
            {
                for (auto* c : n->children)
                    --c->val;
            }

            int64_t root_val = 0;
            for (auto* n : tree)
            {
                if (n->val % 2 == 0)
                {
                    root_val = n->val / 2;
                    --n->val;
                }
            }

            Node* root = nullptr;
            for (auto* n : tree)
            {
                n->val = (1 + n->val) / 2;
                if (n->val == root_val)
                    root = n;
            }

            return root;
        }
    };
}
