#pragma once
#include <algorithm>
#include <vector>

namespace p354
{
    // longest path in dag with dynamic programming - o(n^2)
    // used sorting trick to optimize so we only look ahead (so o(n^2)/2) which barely passes without TLE
    class Solution
    {
      public:
        int maxEnvelopes(std::vector<std::vector<int>>& envelopes)
        {
            auto E = envelopes.size();
            std::vector<std::vector<size_t>> graph(E, std::vector<size_t>{});

            auto includes = [&envelopes](size_t i, size_t j) {
                return envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1];
            };

            std::sort(envelopes.rbegin(), envelopes.rend(),
                      [](const auto& l, const auto& r) { return l[0] * l[1] < r[0] * r[1]; });

            for (size_t i = 0; i < E; ++i)
                for (size_t j = i + 1; j < E; ++j)
                    if (includes(i, j))
                        graph[i].push_back(j);
            // else if (includes(j, i))
            //    graph[j].push_back(i);

            // 0 - not visited
            // 1 - visiting
            // 2 - visited
            std::vector<int> visit_status(E, 0);

            // max path starting at each vertex
            std::vector<int> max_path(E, 0);

            int result = 0;
            for (size_t i = 0; i < E; ++i)
            {
                result = std::max(result, get_max_path(i, graph, visit_status, max_path));
                if (result == E)
                    return result;
            }
            return result;
        }

        int get_max_path(size_t node, const std::vector<std::vector<size_t>>& graph, std::vector<int>& visit_status,
                         std::vector<int>& max_path)
        {
            if (visit_status[node] == 2)
                return max_path[node];

            visit_status[node] = 1;
            int max_path_node = 0;
            for (auto neibour : graph[node])
            {
                // assert (visit_status[neibour] != 1);
                max_path_node = std::max(max_path_node, get_max_path(neibour, graph, visit_status, max_path));
            }
            ++max_path_node;

            visit_status[node] = 2;
            return max_path[node] = max_path_node;
        }
    };

    class Solution2
    {
      public:
        // lis: sort first by x then second descending by y
        //     the longest increasing (in y) sequence in this array will be the max chain
        int maxEnvelopes(std::vector<std::vector<int>>& envelopes)
        {
            std::sort(envelopes.begin(), envelopes.end(),
                      [](const auto& l, const auto& r) { return l[0] != r[0] ? l[0] < r[0] : l[1] > r[1]; });

            std::vector<int> piles;
            for (const auto& e : envelopes)
            {
                auto pos = std::lower_bound(piles.begin(), piles.end(), e[1]);
                if (pos == piles.end())
                    piles.push_back(e[1]);
                else
                    *pos = e[1];
            }

            return piles.size();
        }
    };
}
