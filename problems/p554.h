#pragma once
#include <map>
#include <unordered_set>
#include <vector>

namespace p554
{
    class Solution
    {
      public:
        int leastBricks(std::vector<std::vector<int>>& wall)
        {
            // number of rows in the wall
            auto R = wall.size();

            // maps a height to the indices in the rows that have that height
            std::map<int, std::unordered_set<size_t>> heights;

            // for each wall, the next index to be added
            std::vector<size_t> wall_indices(R, 0);

            // the sums of currently added bricks in each row
            std::vector<int> skyline(R, 0);

            // the number of rows that have reached the end
            size_t done_rows = 0;

            // add the next brick from the wall on row r
            // returns true if the last brick in the row was added
            auto add_brick = [&](size_t r, bool remove) {
                auto new_height_r = skyline[r] + wall[r][wall_indices[r]];

                // remove the old height from the map
                if (remove)
                {
                    auto pos = heights.find(skyline[r]);
                    if (pos != heights.end())
                    {
                        pos->second.erase(r);
                        if (pos->second.empty())
                            heights.erase(pos);
                    }
                }

                // update the skyline
                skyline[r] = new_height_r;

                // add the new height in the map
                heights[new_height_r].insert(r);

                // update the next index in the row
                ++wall_indices[r];

                if (wall_indices[r] == wall[r].size())
                    ++done_rows;
            };

            // add a brick from each wall
            for (size_t r = 0; r < R; ++r)
                add_brick(r, false);
            if (done_rows == R)
                return R;

            // repeat
            // see in which rows the min value appears: RM = {rm0, rm1... rmk}
            //    wall.size() - RM.size() is a line candidate

            // for each of the rows where the min appears, add a brick

            auto best = std::numeric_limits<size_t>::max();
            while (true)
            {
                auto new_line = R - heights.begin()->second.size();
                best = std::min(best, new_line);

                const auto min_indices = heights.begin()->second;

                for (auto i : min_indices)
                    add_brick(i, true);
                if (done_rows == R)
                    return best;
            }

            return -1;
        }
    };

    class Solution2
    {
      public:
        int leastBricks(std::vector<std::vector<int>>& wall)
        {
            std::unordered_map<int, int> gaps;

            for (const auto& row : wall)
            {
                int sum = 0;
                auto R = row.size();
                for (size_t brick = 0; brick < R - 1; ++brick)
                {
                    sum += row[brick];
                    ++gaps[sum];
                }
            }

            // search for the gap with the biggest number of apparitions
            int max = std::numeric_limits<int>::min();
            for (auto [place, apparition_count] : gaps)
                max = std::max(max, apparition_count);

            return max == std::numeric_limits<int>::min() ? int(wall.size()) : wall.size() - max;
        }
    };
}
