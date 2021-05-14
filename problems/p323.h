#pragma once
#include <vector>

namespace p323
{
    class Solution
    {
      public:
        int countComponents(int n, std::vector<std::vector<int>>& edges)
        {
            std::vector<std::vector<int>> graph(size_t(n), std::vector<int>{});
            for (const auto& e : edges)
            {
                graph[e[0]].push_back(e[1]);
                graph[e[1]].push_back(e[0]);
            }

            std::vector<int> color(size_t(n), 0);
            int curr_color = 0;

            for (size_t i = 0; i < size_t(n); ++i)
                if (color[i] == 0)
                    dfs(i, graph, ++curr_color, color);

            return curr_color;
        }

        void dfs(int node, const std::vector<std::vector<int>>& graph, int curr_color, std::vector<int>& color)
        {
            color[node] = curr_color;
            const auto& neighbours = graph[node];
            for (auto n : neighbours)
                if (color[n] == 0)
                    dfs(n, graph, curr_color, color);
        }
    };
}
