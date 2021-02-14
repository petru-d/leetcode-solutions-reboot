#pragma once
#include <vector>

namespace p1649
{
    class Solution2
    {
      public:
        int createSortedArray(std::vector<int>& instructions)
        {
            size_t M = 100002;
            std::vector<int> bit(M);
            int cost = 0;
            auto N = instructions.size();
            for (int i = 0; i < N; i++)
            {
                auto l = query(instructions[i] - 1, bit);
                auto r = i - query(instructions[i], bit);
                cost += std::min(l, r);
                cost %= 1000000007;
                update(instructions[i], 1, bit);
            }

            return cost;
        }

        // implement Binary Index Tree
        void update(int index, int value, std::vector<int>& bit)
        {
            auto M = bit.size();
            index++;
            while (index < M)
            {
                bit[index] += value;
                index += index & -index;
            }
        }

        int query(int index, std::vector<int>& bit)
        {
            index++;
            int result = 0;
            while (index >= 1)
            {
                result += bit[index];
                index -= index & -index;
            }
            return result;
        }
    };

    class Solution
    {
        /*
        Key idea of the tree: at each node we record the number of values that got added
        under and including this node so that at some node `u`, you can query `u.left.subtree_size`
        to find out how many values added that are strictly less than `u` and `u.right.subtree_size`
        for how may strictly greater than `u`.
        
        Since there are duplicate values in instructions, each node in the tree could
        represent multiple instances of the same value added to the tree
        */
        struct Node
        {
            int Val;
            int Quantity = 0;
            int SubtreeQuantity = 0;
            Node* Left = nullptr;
            Node* Right = nullptr;
        };

        Node* make_tree(const std::vector<int>& arr, int L, int R)
        {
            if (L > R)
                return nullptr;
            auto mid = (L + R) / 2;
            Node* root = new Node{arr[mid], 0, 0, nullptr, nullptr};
            root->Left = make_tree(arr, L, mid - 1);
            root->Right = make_tree(arr, mid + 1, R);

            return root;
        }

        void mark_added(Node* tree, int val)
        {
            if (val < tree->Val)
                mark_added(tree->Left, val);
            else if (val > tree->Val)
                mark_added(tree->Right, val);
            else
                ++tree->Quantity;

            ++tree->SubtreeQuantity;
        }

        /*
        After the new value has been marked as added, it just a matter of traversing the
        tree one more time until we reach `v` and note the `subtree_size` along the way
        and add up how many values in the tree is either stricly less than `v` or greater than `v`
        */
        std::pair<int, int> get_less_gt(Node* tree, int val)
        {
            if (tree->Val == val)
                return {tree->Left ? tree->Left->SubtreeQuantity : 0, tree->Right ? tree->Right->SubtreeQuantity : 0};
            if (val < tree->Val)
            {
                auto [less, gt] = get_less_gt(tree->Left, val);
                return {less, gt + (tree->Right ? tree->Right->SubtreeQuantity : 0) + tree->Quantity};
            }

            auto [less, gt] = get_less_gt(tree->Right, val);
            return {less + (tree->Left ? tree->Left->SubtreeQuantity : 0) + tree->Quantity, gt};
        }

      public:
        int createSortedArray(std::vector<int>& instructions)
        {
            auto sorted = instructions;
            std::sort(sorted.begin(), sorted.end());

            auto* tree = make_tree(sorted, 0, int(sorted.size() - 1));

            int cost = 0;
            int mod = 1000000007;
            for (auto i : instructions)
            {
                mark_added(tree, i);

                auto [nb_less, nb_gt] = get_less_gt(tree, i);

                /*
                Node* curr = tree;
                int nb_gt = 0;
                int nb_less = 0;
                while (i != curr->Val)
                {
                    if (i < curr->Val)
                    {
                        nb_gt += (curr->Right ? curr->Right->SubtreeQuantity : 0) + curr->Quantity;
                        curr = curr->Left;
                    }
                    else if (i > curr->Val)
                    {
                        nb_less += (curr->Left ? curr->Left->SubtreeQuantity : 0) + curr->Quantity;
                        curr = curr->Right;
                    }
                }
                nb_less += curr->Left ? curr->Left->SubtreeQuantity : 0;
                nb_gt += curr->Right ? curr->Right->SubtreeQuantity : 0;
                */
                cost = (cost % mod + std::min(nb_less, nb_gt) % mod) % mod;
            }

            return cost;
        }
    };
}
