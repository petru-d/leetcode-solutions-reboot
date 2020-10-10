#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace p399
{
    class Solution
    {
      public:
        struct OutEdge
        {
            double Factor = -1;
            std::string Destination;
        };
        using Node = std::string;
        using Graph = std::unordered_map<Node, std::vector<OutEdge>>;

        std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values,
                                         std::vector<std::vector<std::string>>& queries)
        {
            Graph g;

            size_t NEQ = equations.size();
            for (size_t i = 0; i < NEQ; ++i)
            {
                g[equations[i][0]].push_back(OutEdge{1 / values[i], equations[i][1]});
                g[equations[i][1]].push_back(OutEdge{values[i], equations[i][0]});
            }

            std::vector<double> results;

            for (const auto& q : queries)
            {
                auto posq0 = g.find(q[0]);
                if (posq0 == g.end())
                {
                    results.push_back(-1);
                    continue;
                }

                double curr_factor = 1;
                double global_factor = -1;
                std::unordered_set<Node> visited;
                dfs(g, q[0], q[1], curr_factor, visited, global_factor);
                results.push_back(1 / global_factor);
            }

            return results;
        }

      private:
        void dfs(const Graph& g, const Node& start, const Node& end, double curr_factor, std::unordered_set<Node>& visited,
                 double& global_factor)
        {
            if (global_factor != -1)
                return;

            visited.insert(start);

            if (start == end)
            {
                global_factor = curr_factor;
                return;
            }
            const auto& edges = g.at(start);
            for (const auto& e : edges)
            {
                if (visited.end() != visited.find(e.Destination))
                    continue;
                dfs(g, e.Destination, end, curr_factor * e.Factor, visited, global_factor);
            }
        }
    };
}
