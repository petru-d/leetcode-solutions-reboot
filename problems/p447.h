#pragma once
#include <algorithm>
#include <unordered_map>
#include <vector>

namespace p447
{
    class Solution
    {
      public:
        int numberOfBoomerangs(std::vector<std::vector<int>>& points)
        {
            size_t N = points.size();
            if (N < 3)
                return 0;

            using Point = std::vector<int>;

            auto dist = [](const Point& p1, const Point& p2) {
                return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
            };

            int booms = 0;

            for (size_t pi = 0; pi < N; ++pi)
            {
                std::unordered_map<int, int> others;

                for (size_t pj = 0; pj < N; ++pj)
                    ++others[dist(points[pi], points[pj])];

                for (const auto& [k, v] : others)
                    booms += (v - 1) * v;
            }

            return booms;
        }
    };
}
