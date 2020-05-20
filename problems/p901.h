#pragma once
#include <vector>

namespace p901
{
    //... or just keep the span for each element and jump back from span to span until not possible to jump anymore...
    class StockSpanner
    {
      public:
        StockSpanner()
        {
        }

        int next(int price)
        {
            return insert(_root, price);
        }

      private:
        struct TreeNode
        {
            int Price = 0;
            size_t index = size_t(-1);
            std::vector<TreeNode*> Children;
        };

        TreeNode* _root = nullptr;
        TreeNode* _last = nullptr;

        size_t _global_index = 0;

        int insert(TreeNode* root, int price)
        {
            if (!_root || price >= _root->Price)
            {
                // drop root like an animal - leak all the memory
                _root = new TreeNode{price, ++_global_index, {}};
                _last = _root;
                return static_cast<int>(_global_index);
            }

            // if lower than last, simply insert as a leaf of last (shortcut)
            if (price < _last->Price)
            {
                auto* new_last = new TreeNode{price, ++_global_index, {}};
                _last->Children.push_back(new_last);
                _last = new_last;
                return 1;
            }

            // find the child with the biggest index that has a price strictly higher than the input price
            size_t latest_greater_child_index = size_t(-1);
            for (size_t i = root->Children.size(); i > 0; --i)
            {
                auto* c = root->Children[i - 1];
                if (c->Price > price)
                {
                    latest_greater_child_index = i - 1;
                    break;
                }
            }

            // if no children fit, add the element as a child and return
            if (latest_greater_child_index == size_t(-1))
            {
                _last = new TreeNode{price, ++_global_index, {}};
                root->Children.push_back(_last);
                return static_cast<int>(_global_index - root->index);
            }

            // insert in the found child
            return insert(root->Children[latest_greater_child_index], price);
        }
    };
}
