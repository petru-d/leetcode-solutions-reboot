#pragma once
#include <unordered_map>

namespace p96
{
    class Solution
    {
      public:
        int numTrees(int n)
        {
            unique_vals.insert({0, 1});
            unique_vals.insert({1, 1});

            return get_unique(n);
        }

        int get_unique(int n)
        {
            auto pos_n = unique_vals.find(n);
            if (pos_n != unique_vals.end())
            {
                return pos_n->second;
            }

            int val = 0;
            for (int i = 1; i <= n; ++i)
            {
                val += get_unique(i - 1) * get_unique(n - i);
            }
            unique_vals.insert({n, val});

            return val;
        }

        std::unordered_map<int, int> unique_vals;
    };
}
