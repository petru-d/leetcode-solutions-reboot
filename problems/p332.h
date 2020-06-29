#pragma once
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

namespace p332
{
    class Solution2
    {
      public:
        // using GraphT = std::unordered_map<std::string, std::vector<std::string>>;
        using GraphT = std::unordered_map<std::string,
                                          std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>>>;

        std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets)
        {
            GraphT graph;

            for (const auto& e : tickets)
            {
                graph[e[0]].push(e[1]);
            }

            std::vector<std::string> path;
            dfs("JFK", graph, path);

            std::reverse(path.begin(), path.end());

            return path;
        }

      private:
        void dfs(const std::string& src, GraphT& graph, std::vector<std::string>& path)
        {
            auto& dests = graph[src];
            while (!dests.empty())
            {
                auto next_dest = dests.top();
                dests.pop();
                dfs(next_dest, graph, path);
            }

            path.push_back(src);
        }
    };

    class Solution
    {
      public:
        // using GraphT = std::unordered_map<std::string, std::vector<std::string>>;
        using GraphT = std::unordered_map<std::string,
                                          std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>>>;

        std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets)
        {
            GraphT graph;

            for (const auto& e : tickets)
            {
                graph[e[0]].push(e[1]);
            }

            std::vector<std::string> path;

            std::stack<std::string> q;
            q.push("JFK");
            while (!q.empty())
            {
                auto from = q.top();
                auto& to = graph[from];

                if (!to.empty())
                {
                    q.push(to.top());
                    to.pop();
                }
                else
                {
                    path.push_back(from);
                    q.pop();
                }
            }

            std::reverse(path.begin(), path.end());
            return path;
        }
    };
}
