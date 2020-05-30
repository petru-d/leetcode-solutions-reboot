#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace p207
{
    class Solution
    {
      public:
        // better variation: use 3 colors:
        // - white - non visited
        // - black - done
        // - gray - on the current dfs path
        // if finding gray, a back edge in the dfs is detected - so we have a cycle

        // algo: - if curr node is gray - back edge detected - exit
        //       - mark current white node as gray, launch dfs for non black neibours
        //       - when done with all recursive dfs for one node, mark it black
        bool canFinish2(int numCourses, std::vector<std::vector<int>>& prerequisites)
        {
            std::unordered_map<int, std::vector<int>> graph;
            for (const auto& e : prerequisites)
                graph[e[0]].push_back(e[1]);

            std::vector<int> color(size_t(numCourses), 0);

            auto dfs_cycles = [&color, &graph](const auto& dfs_cycles, int node, std::unordered_set<int>& path) {
                if (color[size_t(node)] == 1)
                    return path.count(node) >= 1;

                color[size_t(node)] = 1;

                const auto& neibours = graph[node];
                for (auto n : neibours)
                {
                    path.insert(node);
                    if (dfs_cycles(dfs_cycles, n, path))
                        return true;
                    path.erase(node);
                }
                return false;
            };

            for (int node = 0; node < numCourses; ++node)
            {
                std::unordered_set<int> path;
                if (color[size_t(node)] == 0 && dfs_cycles(dfs_cycles, node, path))
                    return false;
            }

            return true;
        }

        // much more beautiful algorithm: topological sort + dfs
        bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
        {
            std::unordered_map<int, std::vector<int>> graph;
            std::vector<int> in_degree(size_t(numCourses), 0);
            for (const auto& e : prerequisites)
            {
                graph[e[0]].push_back(e[1]);
                ++in_degree[e[1]];
            }

            std::vector<int> roots;
            for (int i = 0; i < numCourses; ++i)
                if (in_degree[size_t(i)] == 0)
                    roots.push_back(i);

            int taken = 0;
            while (!roots.empty())
            {
                ++taken;
                int root = roots.back();
                roots.pop_back();

                const auto& root_neibours = graph[root];
                for (const auto& n : root_neibours)
                {
                    auto& deg = in_degree[n];
                    if (0 == --deg)
                        roots.push_back(n);
                }
            }

            return taken == numCourses;
        }
    };

}