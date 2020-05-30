#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

namespace p973
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int K)
        {
            auto P = points.size();
            if (P <= K)
                return points;

            std::vector<int> dist;
            dist.reserve(size_t(P));
            for (const auto& p : points)
                dist.push_back(p[0] * p[0] + p[1] * p[1]);

            std::vector<size_t> indices(P, 0);
            std::iota(indices.begin(), indices.end(), 0);

            auto closer = [&dist](size_t i1, size_t i2) { return dist[i1] < dist[i2]; };

            std::vector<size_t> result_indices(size_t(K), 0);
            std::iota(result_indices.begin(), result_indices.end(), 0);
            std::make_heap(result_indices.begin(), result_indices.end(), closer);

            for (size_t i = size_t(K); i < P; ++i)
            {
                if (!closer(i, result_indices.front()))
                    continue;
                std::pop_heap(result_indices.begin(), result_indices.end(), closer);
                result_indices.back() = i;
                std::push_heap(result_indices.begin(), result_indices.end(), closer);
            }

            std::vector<std::vector<int>> result;
            std::transform(result_indices.begin(), result_indices.end(), std::back_inserter(result),
                           [&points](size_t i) { return std::move(points[i]); });

            return result;
        }
    };
}