#pragma once

namespace p116
{
    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;
        Node() : val(0), left(NULL), right(NULL), next(NULL) {}
        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
    };

    class Solution
    {
      public:
        Node* connect(Node* root)
        {
            go(root);

            return root;
        }

        void go(Node* root)
        {
            if (!root || !root->left)
                return;

            go(root->left);
            go(root->right);

            go_lr(root->left, root->right);
        }

        void go_lr(Node* l, Node* r)
        {
            if (!l || !r)
                return;

            l->next = r;

            // can replace this with a simple loop, no need for recursion
            go_lr(l->right, r->left);
        }
    };

    //oana's solution:

    /*
    visit_prev(prev, node)
    {
        prev->next = node;
        visit_prev(prev->right, node->left);
        visit_prev(node->left, node->right);
    }
    */
}
