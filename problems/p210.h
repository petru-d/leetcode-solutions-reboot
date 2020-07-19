#pragma once

#include <unordered_map>
#include <vector>

namespace p210
{
    class Solution
    {
      public:
        using Graph = std::unordered_map<int, std::vector<int>>;

        enum class State
        {
            NotVisited,
            InProgress,
            Visited
        };

        std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
        {
            Graph graph;
            for (const auto& p : prerequisites)
            {
                graph[p[1]].push_back(p[0]);
            }

            std::vector<int> result;

            std::vector<State> visited(size_t(numCourses), State::NotVisited);

            for (int i = 0; i < numCourses; ++i)
            {
                if (visited[i] == State::NotVisited)
                {
                    if (!dfs(i, graph, visited, result))
                        return {};
                }
            }

            std::reverse(result.begin(), result.end());
            return result;
        }

      private:
        bool dfs(int node, const Graph& graph, std::vector<State>& visited, std::vector<int>& result)
        {
            if (visited[size_t(node)] == State::InProgress)
                return false;

            visited[size_t(node)] = State::InProgress;

            auto n_it = graph.find(node);
            if (n_it != graph.end())
            {
                for (const auto& n : n_it->second)
                {
                    if (visited[n] == State::Visited)
                        continue;
                    if (!dfs(n, graph, visited, result))
                        return false;
                }
            }

            visited[node] = State::Visited;
            result.push_back(node);
            return true;
        }
    };
}
