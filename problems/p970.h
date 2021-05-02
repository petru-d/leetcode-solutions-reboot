#pragma once
#include <unordered_set>
#include <vector>

namespace p970
{
    class Solution
    {
      public:
        std::vector<int> powerfulIntegers(int x, int y, int bound)
        {
            if (bound < 2)
                return {};

            if (x > y)
                std::swap(x, y);

            if (y == 1)
                return {2};

            if (x == 1)
            {
                std::vector<int> sol;
                auto yi = 1;
                for (int i = 1;; ++i)
                {
                    if (1 + yi > bound)
                        break;
                    sol.push_back(1 + yi);
                    yi *= y;
                }

                return sol;
            }

            std::unordered_set<int> sol;

            int xi = 1;
            for (int i = 1;; ++i)
            {
                auto left_for_y = bound - xi;
                if (left_for_y <= 0)
                    break;

                int yi = 1;
                for (int j = 1;; ++j)
                {
                    auto left = left_for_y - yi;
                    if (left < 0)
                        break;

                    sol.insert(xi + yi);

                    yi *= y;
                }

                xi *= x;
            }

            std::vector<int> lin_sol;
            lin_sol.reserve(sol.size());
            for (auto s : sol)
                lin_sol.push_back(s);

            return lin_sol;
        }
    };
}
