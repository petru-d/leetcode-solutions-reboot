#pragma once
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace p886
{
    class Solution
    {
      public:
        bool possibleBipartition2(int N, std::vector<std::vector<int>>& dislikes)
        {
            std::vector<int> mask(size_t(N), 0);

            // for fast access, keep also this thing
            std::unordered_map<int, std::unordered_set<size_t>> partition_to_indices;

            int partition_count = 0;

            for (const auto& d : dislikes)
            {
                int p1 = d[0] - 1;
                int p2 = d[1] - 1;

                if (mask[p1] == 0 && mask[p2] == 0)
                {
                    ++partition_count;
                    mask[p1] = partition_count;
                    mask[p2] = -partition_count;

                    partition_to_indices[partition_count].insert(p1);
                    partition_to_indices[-partition_count].insert(p2);
                }
                else if (mask[p1] == 0 && mask[p2] != 0)
                {
                    mask[p1] = -mask[p2];

                    partition_to_indices[-mask[p2]].insert(p1);
                }
                else if (mask[p1] != 0 && mask[p2] == 0)
                {
                    mask[p2] = -mask[p1];

                    partition_to_indices[-mask[p1]].insert(p2);
                }
                else // if (mask[p1] != 0 && mask[p2] != 0)
                {
                    if (mask[p1] == mask[p2])
                        return false;

                    int m1 = mask[p1];
                    int m2 = mask[p2];

                    // everyone with mask m2 should have now mask -m1

                    const auto& pim2 = partition_to_indices[m2];
                    auto& pimm1 = partition_to_indices[-m1];
                    for (auto i : pim2)
                    {
                        mask[i] = -m1;
                        pimm1.insert(i);
                    }
                    partition_to_indices.erase(m2);

                    // std::transform(mask.begin(), mask.end(), mask.begin(), [m1, m2](int i) { return (i == m2) ? -m1 : i; });
                }
            }

            return true;
        }

        bool possibleBipartition(int N, std::vector<std::vector<int>>& dislikes)
        {
            std::vector<std::vector<size_t>> graph(size_t(N), std::vector<size_t>{});
            for (const auto& d : dislikes)
            {
                size_t p1 = d[0] - 1;
                size_t p2 = d[1] - 1;
                graph[p1].push_back(p2);
                graph[p2].push_back(p1);
            }

            std::vector<int> color(size_t(N), 0);

            std::function<bool(size_t, int)> dfs = [&](size_t p, int col) {
                if (color[p] != 0)
                    return color[p] == col;

                color[p] = col;

                const auto& diss = graph[p];
                for (auto d : diss)
                    if (!dfs(d, -col))
                        return false;

                return true;
            };

            for (size_t g = 0; g < size_t(N); ++g)
            {
                if (color[g] != 0)
                    continue;

                if (!dfs(g, 1))
                    return false;
            }

            return true;
        }
    };
}