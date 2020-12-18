#pragma once
#include <vector>

namespace p77
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> combine(int n, int k)
        {
            std::vector<std::vector<int>> sol;
            std::vector<int> curr;
            go(n, k, curr, sol);

            return sol;
        }

        void go(int n, int k, std::vector<int>& curr, std::vector<std::vector<int>>& sol)
        {
            if (curr.size() == size_t(k))
            {
                sol.push_back(curr);
                return;
            }

            int start = curr.empty() ? 1 : curr.back() + 1;

            int end = n - k + int(curr.size()) + 1;

            for (int i = start; i <= end; ++i)
            {
                curr.push_back(i);
                go(n, k, curr, sol);
                curr.pop_back();
            }
        }
    };
}
