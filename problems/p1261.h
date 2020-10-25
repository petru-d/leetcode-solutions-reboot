#pragma once
#include "util_binary_tree.h"

namespace p1261
{
    class FindElements
    {
      public:
        enum class Direction
        {
            Left,
            Right
        };

        FindElements(TreeNode* root)
        {
            if (nullptr != root)
            {
                root->val = 0;
                recover(root->left, 0, Direction::Left);
                recover(root->right, 0, Direction::Right);
            }

            // no ownership
            _recovered = root;
        }

        bool find(int target)
        {
            std::vector<int> path = {target};
            while (target != 0)
            {
                if (target % 2 == 0)
                    target = (target - 2) / 2;
                else
                    target = (target - 1) / 2;

                path.push_back(target);
            }

            std::reverse(path.begin(), path.end());

            return find(_recovered, path, 0);
        }

      private:
        void recover(TreeNode* root, int parentVal, Direction d)
        {
            if (nullptr == root)
                return;

            root->val = (d == Direction::Left ? 2 * parentVal + 1 : 2 * parentVal + 2);

            recover(root->left, root->val, Direction::Left);
            recover(root->right, root->val, Direction::Right);
        }

        bool find(TreeNode* root, const std::vector<int>& path, size_t curr)
        {
            if (root == nullptr)
                return false;

            assert(root->val == path[curr]);

            if (curr == path.size() - 1)
                return true;

            if (path[curr + 1] % 2 == 1)
                return find(root->left, path, curr + 1);

            return find(root->right, path, curr + 1);
        }

        TreeNode* _recovered;
    };
}
