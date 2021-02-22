#pragma once
#include "util_binary_tree.h"
#include <bitset>
#include <cassert>
#include <cmath>

namespace p222
{
    class Solution
    {
      public:
        int countNodes(TreeNode* root)
        {
            if (nullptr == root)
                return 0;

            auto h = get_height_left(root);
            if (h == 0)
                return 1;

            // the last level would have 2^h nodes, if complete
            // see how many it really has
            T = static_cast<int>(pow(2, h));

            int x = -1;
            for (int k = T; k >= 1; k /= 2)
                while (x + k < T && have_node(root, h, x + k))
                    x += k;

            return T + x;
        }

      private:
        int T = -1;

        bool have_node(TreeNode* root, int h, int path)
        {
            if (h == 0)
                return true;

            int bit_h = (1 << (h - 1));
            bool go_left = !(path & bit_h);

            if (go_left)
            {
                return root->left ? have_node(root->left, h - 1, path & ~bit_h) : false;
            }
            return root->right ? have_node(root->right, h - 1, path & ~bit_h) : false;
        }

        // get the height in number of edges
        int get_height_left(TreeNode* root)
        {
            if (root == nullptr)
            {
                assert(false);
                return 0;
            }
            if (root->left == nullptr)
                return 0;
            return 1 + get_height_left(root->left);
        }
    };
}
