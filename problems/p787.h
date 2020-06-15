#pragma once
#include <queue>
#include <unordered_map>
#include <vector>

namespace p787
{
    class Solution
    {
      public:
        int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int K)
        {
            struct Edge
            {
                int Cost = -1;
                int Dest = -1;
            };

            std::unordered_map<int, std::vector<Edge>> graph;
            for (const auto& f : flights)
            {
                int start = f[0];
                int dest = f[1];
                int cost = f[2];

                graph[start].emplace_back(Edge{cost, dest});
            }

            struct Stop
            {
                int Node;
                int DistanceToSrc;
                int Cost;
                bool operator<(const Stop& other) const
                {
                    return Cost > other.Cost;
                }
            };
            std::priority_queue<Stop> q;

            q.push(Stop{src, -1, 0});

            while (!q.empty())
            {
                auto curr = q.top();
                q.pop();

                if (curr.Node == dst)
                    return curr.Cost;

                if (curr.DistanceToSrc >= K)
                    continue;

                const auto& edges = graph[curr.Node];
                for (const auto& edge : edges)
                {
                    Stop newStop{edge.Dest, 1 + curr.DistanceToSrc, curr.Cost + edge.Cost};
                    q.push(newStop);
                }
            }

            return -1;
        }
    };

}
