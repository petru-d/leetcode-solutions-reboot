#pragma once
#include <algorithm>
#include <iterator>
#include <unordered_set>
#include <vector>

namespace p797
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph)
        {
            if (1 == graph.size())
                return {{0}};

            int N = int(graph.size());

            auto have_path = [&graph](int i, int j) {
                if (i == j)
                    return true;

                std::unordered_set<int> curr_row = {i};
                while (!curr_row.empty())
                {
                    std::unordered_set<int> next_row;
                    for (const auto n : curr_row)
                        for (const auto neib : graph[n])
                            if (neib == j)
                                return true;
                            else
                                next_row.insert(neib);

                    curr_row = std::move(next_row);
                }

                return false;
            };

            std::unordered_set<int> relevant_nodes;
            for (int i = 0; i <= N - 1; ++i)
            {
                if (have_path(0, i) && have_path(i, N - 1))
                    relevant_nodes.insert(i);
            }

            if (relevant_nodes.empty())
                return {};

            std::vector<std::vector<int>> solution = {};

            std::vector<std::vector<int>> partial_solution = {{0}};
            while (!partial_solution.empty())
            {
                std::vector<std::vector<int>> expanded_partial_solution;

                for (auto& partial_path : partial_solution)
                {
                    int last = partial_path.back();

                    std::vector<int> relevant_nexts;
                    std::copy_if(graph[last].begin(), graph[last].end(), std::back_inserter(relevant_nexts),
                                 [&relevant_nodes](int neib) { return relevant_nodes.count(neib) > 0; });

                    if (relevant_nexts.empty())
                    {
                        assert(false);
                        continue;
                    }

                    for (const auto rn : relevant_nexts)
                    {
                        auto expanded_partial_path(partial_path);
                        expanded_partial_path.push_back(rn);

                        ((rn == N - 1) ? solution : expanded_partial_solution).push_back(std::move(expanded_partial_path));
                    }
                }

                partial_solution = std::move(expanded_partial_solution);
            }

            return {solution};
        }
    };
}
