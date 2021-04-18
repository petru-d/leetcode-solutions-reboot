#pragma once
#include <vector>

namespace p443
{
    class Solution
    {
      public:
        int compress(std::vector<char>& chars)
        {
            size_t compressed_end = 0; // one over
            size_t uncompressed_start = 0;

            auto C = chars.size();
            while (uncompressed_start < C)
            {
                auto curr = chars[uncompressed_start];
                size_t count_curr = 0;
                while (uncompressed_start + count_curr < C && chars[uncompressed_start + count_curr] == curr)
                    ++count_curr;

                chars[compressed_end++] = curr;

                if (count_curr > 1)
                {
                    auto count_curr_str = std::to_string(count_curr);
                    for (auto c : count_curr_str)
                        chars[compressed_end++] = c;
                }

                uncompressed_start += count_curr;
            }

            return compressed_end;
        }
    };
}
