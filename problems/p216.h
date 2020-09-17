#pragma once
#include <vector>

namespace p216
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> combinationSum3(int k, int n)
        {
            std::vector<int> sol;
            go(k, n, sol);

            return _solutions;
        }

      private:
        void go(int k, int n, std::vector<int>& sol)
        {
            if (k == 1)
            {
                if (n <= 9 && (sol.empty() || n > sol.back()))
                {
                    sol.push_back(n);
                    _solutions.push_back(sol);
                    sol.pop_back();
                }
                return;
            }

            int low = sol.empty() ? 1 : sol.back() + 1;
            for (int i = low; i <= 9; ++i)
            {
                sol.push_back(i);
                go(k - 1, n - i, sol);
                sol.pop_back();
            }
        };

        std::vector<std::vector<int>> _solutions;
    };
}
