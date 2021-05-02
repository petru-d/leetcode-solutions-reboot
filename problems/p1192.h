#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace p1192
{
    class Solution
    {
      public:
        struct pair_hash
        {
            inline size_t operator()(const std::pair<int, int>& v) const
            {
                size_t h = (size_t(v.first) << 32) + size_t(v.second);
                h *= 1231231557ull; // "random" uneven integer
                h ^= (h >> 32);
                return h;
            }
        };

        std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>>& connections)
        {
            std::unordered_map<int, std::vector<int>> graph;
            std::unordered_set<std::pair<int, int>, pair_hash> kill_graph;
            std::vector<int> rank(size_t(n), -1);

            for (const auto& c : connections)
            {
                graph[c[0]].push_back(c[1]);
                graph[c[1]].push_back(c[0]);

                kill_graph.insert({std::min(c[0], c[1]), std::max(c[0], c[1])});
            }

            dfs(0, 0, graph, kill_graph, rank);

            std::vector<std::vector<int>> result;
            for (auto [k, v] : kill_graph)
                result.push_back({k, v});

            return result;
        }

      private:
        // if we find a neighbor with a smaller rank than our discovery time, the edge to the neighbor needs to be discarded.
        int dfs(int node, int discoveryRank, std::unordered_map<int, std::vector<int>>& graph,
                std::unordered_set<std::pair<int, int>, pair_hash>& kill_graph, std::vector<int>& rank)
        {

            // That means this node is already visited. We simply return the rank.
            if (rank[size_t(node)] != -1)
                return rank[size_t(node)];

            // Update the rank of this node and keep track of the minimum rank encountered.
            int minRank = rank[node] = discoveryRank;

            for (auto neighbor : graph[node])
            {
                // Skip the parent.
                auto neighRank = rank[neighbor];
                if (neighRank != -1 && neighRank == discoveryRank - 1)
                    continue;

                // Recurse on the neighbor.
                int recursiveRank = dfs(neighbor, discoveryRank + 1, graph, kill_graph, rank);

                // Check if this edge needs to be discarded.
                if (recursiveRank <= discoveryRank)
                    kill_graph.erase({std::min(node, neighbor), std::max(node, neighbor)});

                // Update the minRank if needed.
                minRank = std::min(minRank, recursiveRank);
            }

            return minRank;
        }
    };
}
