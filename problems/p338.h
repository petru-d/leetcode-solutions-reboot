#pragma once
#include <vector>

namespace p338
{
    class Solution
    {
      public:
        std::vector<int> countBits(int num)
        {
            if (num == 0)
                return {0};
            if (num == 1)
                return {0, 1};

            std::vector<int> result = {0, 1};
            result.reserve(size_t(num) + 1);

            size_t iteration_len = 1;
            while (true)
            {
                for (int h = 0; h < 2; ++h)
                {
                    auto curr_size = result.size();
                    for (size_t i = 0; i < iteration_len; ++i)
                    {
                        result.push_back(result[curr_size - iteration_len + i] + h);
                        if (result.size() == num + 1)
                            goto exit;
                    }
                }

                iteration_len *= 2;
            }

        exit:
            return result;
        }
    };
}