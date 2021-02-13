#pragma once
#include <vector>
#include <unordered_map>
#include <queue>

namespace p1345
{
    class Solution
    {
      public:
        int minJumps(std::vector<int>& arr)
        {
            std::vector<int> visited(arr.size(), 0);

            std::unordered_map<int, std::vector<size_t>> same_val;
            for (size_t i = arr.size(); i > 0; --i)
            {
                same_val[arr[i - 1]].push_back(i - 1);
            }

            std::deque<size_t> curr = {0};
            int steps = 0;

            while (!curr.empty())
            {
                size_t n = curr.size();
                for (size_t i = 0; i < n; ++i)
                {
                    auto node = curr.front();
                    curr.pop_front();

                    if (node == arr.size() - 1)
                        return steps;

                    visited[node] = 1;

                    int nodeval = arr[node];
                    const auto& same_vals = same_val[nodeval];
                    for (const auto& v : same_vals)
                    {
                        if (v != node && visited[v] == 0)
                        {
                            // test if arr[v] is surrounded by the same crap. if yes, don't add it
                            if (!(v > 0 && arr[v - 1] == arr[v] && v < arr.size() - 1 && arr[v + 1] == arr[v]))
                                curr.push_back(v);
                        }
                    }

                    if (node > 0 && visited[node - 1] == 0)
                        curr.push_back(node - 1);

                    if (visited[node + 1] == 0)
                        curr.push_back(node + 1);
                }
                ++steps;
            }

            return -1;
        }
    };
}
