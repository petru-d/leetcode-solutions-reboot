#pragma once
#include <charconv>
#include <string>
#include <vector>

namespace p165
{
    class Solution
    {
      public:
        int compareVersion(std::string version1, std::string version2)
        {
            std::vector<int> v1 = getV(version1);
            std::vector<int> v2 = getV(version2);

            int swap = 1;
            if (v1.size() > v2.size())
            {
                std::swap(v1, v2);
                swap = -1;
            }
            auto pad = v2.size() - v1.size();
            for (size_t i = 0; i < pad; ++i)
                v1.push_back(0);

            auto N = std::min(v1.size(), v2.size());
            for (size_t i = 0; i < N; ++i)
            {
                if (v1[i] < v2[i])
                    return -1 * swap;
                if (v1[i] > v2[i])
                    return 1 * swap;
            }

            return 0;
        }

      private:
        std::vector<int> getV(const std::string& version)
        {
            size_t N = version.size();
            if (N == 0)
                return {};

            std::vector<int> result;

            size_t curr = 0;
            while (curr < N)
            {
                auto dotPos = version.find('.', curr);
                if (dotPos == std::string::npos)
                    dotPos = N;
                int r = 0;
                if (auto [p, ec] = std::from_chars(version.data() + curr, version.data() + dotPos, r); ec == std::errc())
                    result.push_back(r);

                curr = ++dotPos;
            }

            return result;
        }
    };
}
