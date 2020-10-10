#pragma once
#include <algorithm>
#include <vector>

namespace p452
{
    class Solution
    {
      public:
        int findMinArrowShots(std::vector<std::vector<int>>& points)
        {
            size_t N = points.size();
            if (N <= 1)
                return int(N);

            struct BaloonEdge
            {
                int Pos = 0;
                size_t Id = -1;
                bool IsEnd = false;
                BaloonEdge(int pos, size_t id, bool isEnd) : Pos(pos), Id(id), IsEnd(isEnd){};
                bool operator<(const BaloonEdge& other) const
                {
                    if (Pos != other.Pos)
                        return Pos < other.Pos;
                    return !IsEnd && other.IsEnd;
                }
            };

            std::vector<BaloonEdge> edges;
            edges.reserve(N);

            for (size_t i = 0; i < N; ++i)
            {
                edges.emplace_back(points[i][0], i, false);
                edges.emplace_back(points[i][1], i, true);
            }
            std::sort(edges.begin(), edges.end());

            int result = 0;

            std::vector<bool> popped(N, false);
            std::vector<size_t> to_pop;
            for (size_t i = 0; i < 2 * N; ++i)
            {
                if (!edges[i].IsEnd)
                    to_pop.push_back(edges[i].Id);
                else
                {
                    if (!popped[edges[i].Id])
                    {
                        ++result;
                        for (auto p : to_pop)
                            popped[p] = true;
                        to_pop.clear();
                    }
                }
            }

            return result;
        }
    };
}
