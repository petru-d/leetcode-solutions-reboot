#pragma once

#include <algorithm>
#include <array>
#include <vector>

namespace p264
{
    class Solution
    {
      public:
        int nthUglyNumber(int n)
        {
            if (n <= 6)
                return n;

            std::vector<int> uglies = {1, 2, 3, 4, 5, 6};
            uglies.reserve(n);

            // smallest index such as 2 * uglies[index] > uglies.back();
            // smallest index such as 3 * uglies[index] > uglies.back();
            // smallest index such as 5 * uglies[index] > uglies.back();
            std::array<size_t, 3> index_p = {3, 2, 1};
            std::array<int, 3> p = {2, 3, 5};
            std::array<int, 3> vals = {};

            while (uglies.size() < n)
            {
                for (size_t i = 0; i < 3; ++i)
                    vals[i] = p[i] * uglies[index_p[i]];

                auto mini = *std::min_element(vals.begin(), vals.end());
                uglies.push_back(mini);

                for (size_t i = 0; i < 3; ++i)
                    if (vals[i] == mini)
                        ++index_p[i];
            }

            return static_cast<int>(uglies.back());
        }

        int nthUglyNumber2(int n)
        {
            if (n <= 6)
                return n;

            std::vector<uint64_t> uglies = {1, 2, 3, 4, 5, 6};
            uglies.reserve(n);

            while (uglies.size() < n)
            {
                size_t pos2 = search(uglies, 2);
                size_t pos3 = search(uglies, 3);
                size_t pos5 = search(uglies, 5);

                uglies.push_back(std::min({2 * uglies[pos2], 3 * uglies[pos3], 5 * uglies[pos5]}));
            }

            return static_cast<int>(uglies.back());
        }

      private:
        size_t search(const std::vector<uint64_t>& uglies, int factor)
        {
            auto greater = [&uglies, factor](int index) { return uglies[index] * factor > uglies.back(); };

            auto U = static_cast<int>(uglies.size() - 1);

            // search for the first k such as uglies[k] * factor > uglies.back()
            int x = -1;
            for (int b = U; b >= 1; b /= 2)
                while (!greater(b + x))
                    x += b;

            return static_cast<size_t>(x) + 1;
        }
    };
}
