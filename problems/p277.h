#pragma once
#include <algorithm>
#include <numeric>
#include <vector>
namespace p277
{
    class Solution
    {
      public:
        Solution(std::vector<std::pair<int, int>>&& graph) : _graph(graph)
        {
        }

        bool knows(int i, int j)
        {
            return std::find_if(_graph.begin(), _graph.end(), [i, j](const auto& ij) { return std::pair(i, j) == ij; }) !=
                   _graph.end();
        }

        int findCelebrity(int n)
        {
            std::vector<int> maybes(n, 0);
            std::iota(maybes.begin(), maybes.end(), 0);

            while (maybes.size() > 1)
            {
                std::vector<int> next_maybes;
                next_maybes.reserve(1 + maybes.size() / 2);

                for (size_t i = 0; i < maybes.size(); i += 2)
                {
                    if (i == maybes.size() - 1)
                        next_maybes.push_back(maybes[i]);
                    else
                    {
                        auto k = knows(maybes[i], maybes[i + 1]);
                        next_maybes.push_back(k ? maybes[i + 1] : maybes[i]);
                    }
                }
                // p(next_maybes);
                std::swap(maybes, next_maybes);
            }
            // cout << maybes[0];

            for (int i = 0; i < n; ++i)
            {
                if (i == maybes[0])
                    continue;

                if (!knows(i, maybes[0]) || knows(maybes[0], i))
                    return -1;
            }

            return maybes[0];
        }

      private:
        std::vector<std::pair<int, int>> _graph;
    };
}
