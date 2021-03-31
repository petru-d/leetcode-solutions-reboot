#pragma once
#include <unordered_set>
#include <vector>

namespace p1136
{
    // breadth first - topological sort
    class Solution
    {
      public:
        int minimumSemesters(int n, std::vector<std::vector<int>>& relations)
        {
            struct Node
            {
                std::vector<int> Children;
                size_t InDegree = 0;
                bool Took = false;
            };

            // graph[i] contains info about the course with ID i+1
            std::vector<Node> graph(n, Node{});

            std::unordered_set<int> zeroInDegree;
            for (int i = 1; i <= n; ++i)
                zeroInDegree.insert(i);

            int takenCount = 0;
            for (const auto& rel : relations)
            {
                int prereq = rel[0];
                int course = rel[1];

                graph[prereq - 1].Children.push_back(course);
                ++graph[course - 1].InDegree;
                if (1 == graph[course - 1].InDegree)
                    zeroInDegree.erase(course);
            }

            int result = 0;
            while (!zeroInDegree.empty())
            {
                takenCount += zeroInDegree.size();
                ++result;

                std::unordered_set<int> nextZeroInDegree;
                for (auto take : zeroInDegree)
                {
                    const auto& takeChildren = graph[take - 1].Children;
                    for (auto c : takeChildren)
                    {
                        --graph[c - 1].InDegree;
                        if (graph[c - 1].InDegree == 0)
                            nextZeroInDegree.insert(c);
                    }
                }
                std::swap(zeroInDegree, nextZeroInDegree);
            }

            return takenCount == n ? result : -1;
        }
    };

    // dfs - longest path starting from a point is the max of the longest paths starting from the children + 1
    // memoize stuff to avoid unneeded work
    class Solution2
    {
      public:
        int minimumSemesters(int n, std::vector<std::vector<int>>& relations)
        {
            std::vector<std::vector<int>> graph(n + 1, std::vector<int>{});
            for (const auto& r : relations)
            {
                auto prereq = r[0];
                auto course = r[1];
                graph[prereq].push_back(course);
            }

            std::vector<int> longestPaths(n + 1, 0);

            // 0: not started
            // 1: visiting
            // 2: finalized
            std::vector<int> state(n + 1, 0);

            int result = 0;
            for (int i = 1; i <= n; ++i)
            {
                auto [cycle_detected, max_path_i] = dfs(i, graph, longestPaths, state);
                if (cycle_detected)
                    return -1;
                result = std::max(result, max_path_i);
            }

            return result;
        }

        std::pair<bool, int> dfs(int current_node, const std::vector<std::vector<int>>& graph, std::vector<int>& longestPaths,
                                 std::vector<int>& state)
        {
            if (state[current_node] == 2)
                return {false, longestPaths[current_node]};

            state[current_node] = 1;

            int max_current_node = 0;
            for (auto child : graph[current_node])
            {
                // cycle detected
                if (state[child] == 1)
                    return {true, std::numeric_limits<int>::max()};

                auto [cycle_detected_child, max_path_child] = dfs(child, graph, longestPaths, state);
                if (cycle_detected_child)
                    return {true, std::numeric_limits<int>::max()};

                max_current_node = std::max(max_current_node, max_path_child);
            }

            state[current_node] = 2;
            longestPaths[current_node] = 1 + max_current_node;

            return {false, 1 + max_current_node};
        }
    };
}
