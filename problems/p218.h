#pragma once
#include <queue>
#include <vector>

namespace p218
{
    class Solution
    {
      public:
        // std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings)
        //{
        //    std::vector<std::vector<int>> res;
        //    size_t cur = 0;
        //    size_t len = buildings.size();

        //    // max heap of "live" buildings, by {height, end_time}
        //    std::priority_queue<std::pair<int, int>> liveBlg;
        //
        //    while (cur < len || !liveBlg.empty())
        //    {
        //        // if either some new building is not processed or live building queue is not empty
        //        int cur_X = liveBlg.empty() ? buildings[cur][0] : liveBlg.top().second; // next timing point to process

        //        if (cur >= len || buildings[cur][0] > cur_X)
        //        {
        //            // first check if the current tallest building will end before the next timing point
        //            // pop up the processed buildings, i.e. those  have height no larger than cur_H and end before the top one
        //            while (!liveBlg.empty() && (liveBlg.top().second <= cur_X))
        //                liveBlg.pop();
        //        }
        //        else
        //        {
        //            // if the next new building starts before the top one ends, process the new building in the vector
        //            cur_X = buildings[cur][0];
        //            while (cur < len &&
        //                   buildings[cur][0] == cur_X) // go through all the new buildings that starts at the same point
        //            {                                  // just push them in the queue
        //                liveBlg.push(std::make_pair(buildings[cur][2], buildings[cur][1]));
        //                cur++;
        //            }
        //        }

        //        int cur_H = liveBlg.empty() ? 0 : liveBlg.top().first; // output the top one
        //        if (res.empty() || ((res.back())[1] != cur_H))
        //            res.push_back({cur_X, cur_H});
        //    }
        //    return res;
        //}

        std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings)
        {
            struct CriticalPoint
            {
                int X;
                bool Left;
                size_t BuilingId;
            };

            std::vector<CriticalPoint> criticals;
            criticals.reserve(2 * buildings.size());

            for (size_t b = 0; b < buildings.size(); ++b)
            {
                criticals.push_back({buildings[b][0], true, b});
                criticals.push_back({buildings[b][1], false, b});
            }

            std::sort(criticals.begin(), criticals.end(),
                      [](const CriticalPoint& l, const CriticalPoint& r) { return l.X < r.X; });

            std::vector<std::vector<int>> result;

            auto less_by_height = [&](size_t leftId, size_t rightId) { return buildings[leftId][2] < buildings[rightId][2]; };

            // std::priority_queue<size_t, std::vector<size_t>, decltype(less_by_height)> alive(less_by_height);

            std::multiset<size_t, decltype(less_by_height)> alive(less_by_height);

            for (size_t c = 0; c < criticals.size();)
            {
                int x = criticals[c].X;
                while (c < criticals.size() && x == criticals[c].X)
                {
                    if (criticals[c].Left)
                        alive.insert(criticals[c].BuilingId);
                    else
                    {
                        auto pos = alive.find(criticals[c].BuilingId);
                        alive.erase(pos);
                        //alive.erase(criticals[c].BuilingId);
                    }
                    ++c;
                }

                int height = 0;
                if (!alive.empty())
                {
                    // size_t b = alive.top();
                    size_t b = *alive.rbegin();
                    height = buildings[b][2];
                }

                if (result.empty() || result.back()[1] != height)
                    result.push_back({x, height});
            }

            return result;
        }
    };

}
