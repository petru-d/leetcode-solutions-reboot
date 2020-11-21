#pragma once
#include <vector>
#include <queue>

namespace p310
{
    class Solution
    {
      public:
        std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges)
        {
            // Base case: only one node
            if (n == 1)
                return {0};

            // graph adjacency list of nodes
            std::vector<std::vector<int>> graph(n);

            // degree count of nodes
            std::vector<int> degree(n, 0);

            // populate graph adjacency list and degree count of nodes
            for (int i = 0; i < edges.size(); i++)
            {
                int a = edges[i][0];
                int b = edges[i][1];

                graph[a].push_back(b);
                graph[b].push_back(a);

                degree[a]++;
                degree[b]++;
            }

            std::queue<int> leaves;
            for (int i = 0; i < n; i++)
                if (degree[i] == 1)
                    leaves.push(i);

            // MHT root nodes
            std::vector<int> res;

            // run BFS until queue is empty
            while (!leaves.empty())
            {
                int n = int(leaves.size());

                // clear root nodes
                res.clear();

                // perform level order traverse
                while (n--)
                {
                    int node = leaves.front();
                    leaves.pop();

                    // add current in to root node vector
                    res.push_back(node);

                    // process neighbour nodes
                    for (int i = 0; i < graph[node].size(); i++)
                    {
                        // decrease degree of neighbour nodes
                        degree[graph[node][i]]--;

                        // push leaf nodes in to queue
                        if (degree[graph[node][i]] == 1)
                        {
                            leaves.push(graph[node][i]);
                        }
                    }
                }
            }

            // root nodes of MHT
            return res;
        }
    };
}
