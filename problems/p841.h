#pragma once
#include <vector>

namespace p841
{
    class Solution
    {
      public:
        bool canVisitAllRooms(std::vector<std::vector<int>>& rooms)
        {
            std::vector<int> visited(rooms.size(), 0);

            size_t visitedCount = 0;
            visit(rooms, 0, visited, visitedCount);

            return visitedCount == visited.size();
        }

        void visit(const std::vector<std::vector<int>>& rooms, size_t curr, std::vector<int>& visited, size_t& visitedCount)
        {
            ++visitedCount;
            visited[curr] = 1;
            for (auto key : rooms[curr])
            {
                if (visited[key] == 0)
                    visit(rooms, key, visited, visitedCount);
            }
        }
    };
}
