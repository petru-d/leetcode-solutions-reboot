#pragma once
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace p368
{
    class Solution_graphs
    {
      public:
        std::vector<int> largestDivisibleSubset(std::vector<int>& nums)
        {
            if (nums.empty())
                return {};

            std::sort(nums.begin(), nums.end());

            std::map<int, std::vector<int>> graph;

            graph[nums[0]] = {};
            for (size_t i = 1; i < nums.size(); ++i)
            {
                std::vector<int> added;
                for (auto itg = graph.rbegin(); itg != graph.rend(); ++itg)
                {
                    auto node = itg->first;
                    if (nums[i] % node == 0 &&
                        added.end() == std::find_if(added.begin(), added.end(), [node](int a) { return a % node == 0; }))
                    {
                        graph[node].push_back(nums[i]);
                        added.push_back(node);
                    }
                }
                graph[nums[i]] = {};
            }

            std::pair<int, size_t> best_node_len = {-1, 0};
            std::unordered_map<int, std::pair<int, size_t>> best_paths_lens;
            for (const auto& [n, e] : graph)
            {
                if (best_paths_lens.find(n) == best_paths_lens.end())
                    get_best_path(n, graph, best_paths_lens, best_node_len);
            }

            if (best_node_len.first == -1)
                return {nums[0]};

            std::vector<int> result;
            int curr = best_node_len.first;

            while (curr != -1)
            {
                result.push_back(curr);
                curr = best_paths_lens[curr].first;
            }

            return result;
        }

      private:
        void get_best_path(int node, std::map<int, std::vector<int>>& graph,
                           std::unordered_map<int, std::pair<int, size_t>>& best_paths_lens,
                           std::pair<int, size_t>& best_node_len)
        {
            const auto& neibs = graph[node];

            if (neibs.empty())
            {
                best_paths_lens[node] = {-1, 0};
                return;
            }

            std::vector<std::pair<int, size_t>> best_n;

            for (auto n : neibs)
            {
                auto posn = best_paths_lens.find(n);
                if (posn == best_paths_lens.end())
                    get_best_path(n, graph, best_paths_lens, best_node_len);

                best_n.push_back({n, best_paths_lens[n].second});
            }

            auto best = *std::max_element(best_n.begin(), best_n.end(), [](auto l, auto r) { return l.second < r.second; });

            best_paths_lens[node] = {best.first, 1 + best.second};
            if (best_node_len.second < 1 + best.second)
            {
                best_node_len = {node, 1 + best.second};
            }
        }
    };

    class Solution
    {
      public:
        std::vector<int> largestDivisibleSubset(std::vector<int>& nums)
        {
            if (nums.empty())
                return {};

            std::sort(nums.begin(), nums.end());

            std::vector<size_t> best_subset(nums.size(), 1);
            std::vector<size_t> prev_index(nums.size(), size_t(-1));

            size_t best_index = 0;
            size_t best_val = 0;

            for (size_t i = 0; i < nums.size(); ++i)
            {
                for (size_t j = 0; j < i; ++j)
                {
                    if (nums[i] % nums[j] == 0 && best_subset[i] < best_subset[j] + 1)
                    {
                        best_subset[i] = best_subset[j] + 1;
                        prev_index[i] = j;

                        if (best_val < best_subset[i])
                        {
                            best_val = best_subset[i];
                            best_index = i;
                        }
                    }
                }
            }

            std::vector<int> result;
            size_t curr_index = best_index;
            while (curr_index != size_t(-1))
            {
                result.push_back(nums[curr_index]);
                curr_index = prev_index[curr_index];
            }

            return result;
        }
    };
}
