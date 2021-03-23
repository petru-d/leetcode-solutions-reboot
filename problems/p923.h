#pragma once
#include <cstdint>
#include <map>
#include <vector>

namespace p923
{
    class Solution
    {
      public:
        int threeSumMulti(std::vector<int>& arr, int target)
        {
            std::map<int, size_t> data;
            for (auto a : arr)
                ++data[a];

            uint64_t M = 1000000007;
            uint64_t result = 0;
            for (auto first = data.begin(); first != data.end(); ++first)
            {
                if (3 * first->first == target && first->second >= 3)
                {
                    result += (first->second - 2) * (first->second - 1) * first->second / 6 % M;
                    result %= M;
                }
                for (auto second = std::next(first); second != data.end(); ++second)
                {
                    if (2 * first->first + second->first == target)
                    {
                        result += (first->second - 1) * first->second / 2 * second->second % M;
                        result %= M;
                    }
                    if (first->first + 2 * second->first == target)
                    {
                        result += first->second * (second->second - 1) * second->second / 2 % M;
                        result %= M;
                    }

                    auto third = data.find(target - first->first - second->first);
                    if (third == data.end() || third->first <= second->first)
                        continue;

                    result += (first->second * second->second * third->second) % M;
                    result %= M;
                }
            }

            return int(result);
        }
    };
}
