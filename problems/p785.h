#pragma once
#include <vector>

namespace p785
{
    class Solution
    {
      public:
        bool dfs(const std::vector<std::vector<int>>& graph, int point, std::vector<int>& color, int start_color)
        {
            if (color[point] == start_color)
                return true;
            if (color[point] != -1)
                return false;

            color[point] = start_color;
            for (int i = 0; i < graph[point].size(); ++i)
            {
                int neibour = graph[point][i];
                if (!dfs(graph, neibour, color, (start_color + 1) % 2))
                    return false;
            }

            return true;
        }

        bool isBipartite(std::vector<std::vector<int>>& graph)
        {
            std::vector<int> color(graph.size(), -1);

            for (int i = 0; i < int(graph.size()); ++i)
            {
                if (color[i] != -1)
                    continue;

                if (!dfs(graph, i, color, 0))
                    return false;
            }

            return true;
        }
    };
}
