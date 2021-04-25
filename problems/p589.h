#pragma once
#include <stack>
#include <vector>

namespace p589
{
    class Node
    {
      public:
        int val;
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

    class Solution2
    {
      public:
        std::vector<int> preorder(Node* root)
        {
            std::vector<int> res;
            go(root, res);
            return res;
        }

        void go(Node* root, std::vector<int>& res)
        {
            if (!root)
                return;

            res.push_back(root->val);

            for (auto* c : root->children)
                go(c, res);
        }
    };

    class Solution
    {
      public:
        std::vector<int> preorder(Node* root)
        {
            if (!root)
                return {};

            std::vector<int> res;

            std::stack<Node*> s;
            s.push(root);

            while (!s.empty())
            {
                auto* t = s.top();
                res.push_back(t->val);

                s.pop();

                for (auto c = t->children.size(); c > 0; --c)
                    s.push(t->children[c - 1]);
            }

            return res;
        }
    };
}
