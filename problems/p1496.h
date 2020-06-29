#pragma once
#include <cassert>
#include <set>
#include <string>

namespace p1496
{
    class Solution
    {
      public:
        bool isPathCrossing(std::string path)
        {
            std::set<std::pair<int, int>> points = {{0, 0}};
            std::pair<int, int> last_point = {0, 0};
            for (auto p : path)
            {
                if (p == 'N')
                    ++last_point.second;
                else if (p == 'S')
                    --last_point.second;
                else if (p == 'E')
                    ++last_point.first;
                else if (p == 'W')
                    --last_point.first;
                else
                    assert(false);

                auto it = points.find(last_point);
                if (it != points.end())
                    return true;

                points.insert(last_point);
            }

            return false;
        }
    };
}
