#pragma once
#include <array>
#include <cassert>
#include <set>
#include <vector>

namespace p1094
{

    // class Solution
    //{
    //  public:
    //    bool carPooling(std::vector<std::vector<int>>& trips, int capacity)
    //    {
    //        std::array<uint16_t, 1001> load = {};

    //        for (const auto& t : trips)
    //        {
    //            auto people = uint16_t(t[0]);
    //            auto from = size_t(t[1]);
    //            auto to = size_t(t[2]);

    //            for (auto i = from; i < to; ++i)
    //            {
    //                load[i] += people;
    //                if (load[i] > capacity)
    //                    return false;
    //            }
    //        }

    //        return true;
    //    }
    //};

    class Solution
    {
      public:
        bool carPooling(std::vector<std::vector<int>>& trips, int capacity)
        {
            std::array<int16_t, 1001> load = {};

            for (const auto& t : trips)
            {
                auto people = int16_t(t[0]);
                auto from = size_t(t[1]);
                auto to = size_t(t[2]);

                load[from] += people;
                load[to] -= people;
            }

            for (size_t i = 0; i < 1001; ++i)
            {
                capacity -= load[i];
                if (capacity < 0)
                    return false;
            }

            return true;
        }
    };
}
