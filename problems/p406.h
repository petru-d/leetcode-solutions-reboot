#pragma once
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>

namespace p406
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> reconstructQueue_first_version(std::vector<std::vector<int>>& people)
        {
            std::map<int, std::vector<std::vector<int>>> height_to_people;
            for (auto& p : people)
            {
                auto p_height = p[0];
                height_to_people[p_height].emplace_back(std::move(p));
            }

            std::vector<std::vector<int>> reconstructed(people.size(), std::vector<int>{});
            std::vector<bool> occupied(people.size(), false);

            size_t current_height_class = 0;
            for (auto& [h, peeps] : height_to_people)
            {
                for (auto& p : peeps)
                {
                    int k = p[1];
                    if (current_height_class == 0)
                    {
                        reconstructed[k] = std::move(p);
                        occupied[k] = true;
                    }
                    else
                    {
                        // the hard way - count k unnocupied or occupied with same height
                        int k_found = -1;
                        size_t u = 0;
                        for (u = 0; u < occupied.size() && k_found < k; ++u)
                            if (!occupied[u] || (occupied[u] && reconstructed[u][0] == h))
                            {
                                ++k_found;
                                if (k == k_found)
                                    break;
                            }

                        reconstructed[u] = std::move(p);
                        occupied[u] = true;
                    }
                }

                ++current_height_class;
            }

            return reconstructed;
        }

        std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people)
        {
            auto less_people = [](const std::vector<int>& p1, const std::vector<int>& p2) {
                if (p1[0] != p2[0])
                    return p1[0] < p2[0];
                return p1[1] < p2[1];
            };

            std::set<std::vector<int>, decltype(less_people)> by_h_by_k;
            for (auto& p : people)
            {
                by_h_by_k.emplace(std::move(p));
            }

            std::vector<std::vector<int>> reconstructed(people.size(), std::vector<int>{});
            std::vector<bool> occupied(people.size(), false);

            int prev_h = -1;
            int prev_k = -1;
            size_t prev_pos = -1;

            for (auto& p : by_h_by_k)
            {
                int h = p[0];
                int k = p[1];

                if (h != prev_h)
                {
                    prev_pos = -1;
                    prev_k = -1;
                }

                // search starting from prev_pos + 1 for the (k - prev_k)'th unoccupied slot
                int target_k = k - prev_k;
                int found_k = 0;
                size_t pos = -1;
                for (pos = prev_pos + 1; pos < occupied.size(); ++pos)
                {
                    if (!occupied[pos])
                    {
                        ++found_k;
                        if (found_k == target_k)
                            break;
                    }
                }

                // occupy
                reconstructed[pos] = std::move(p);
                occupied[pos] = true;

                // for next time
                prev_h = h;
                prev_k = k;
                prev_pos = pos;
            }

            return reconstructed;
        }
    };
}