#pragma once
#include <vector>
#include <unordered_map>

namespace p1640
{
    class Solution
    {
      public:
        bool canFormArray(std::vector<int>& arr, std::vector<std::vector<int>>& pieces)
        {
            std::unordered_map<int, size_t> h;
            auto A = arr.size();
            for (size_t i = 0; i < A; ++i)
                h[arr[i]] = i;

            for (const auto& p : pieces)
            {
                auto startPos = h.find(p[0]);
                if (startPos == h.end())
                    return false;
                auto P = p.size();
                for (size_t i = 1; i < P; ++i)
                {
                    if (i + startPos->second >= A || arr[i + startPos->second] != p[i])
                        return false;
                }
            }

            return true;
        }
    };
}
