#pragma once
#include <vector>

namespace p977
{
    class Solution
    {
      public:
        std::vector<int> sortedSquares(std::vector<int>& nums)
        {
            size_t N = nums.size();

            size_t indexGZ = 0;
            while (indexGZ < N && nums[indexGZ] < 0)
            {
                nums[indexGZ] *= nums[indexGZ];
                ++indexGZ;
            }

            for (size_t i = indexGZ; i < N; ++i)
                nums[i] *= nums[i];

            std::vector<int> result(N, 0);
            size_t i = 0;
            size_t currN = indexGZ;
            size_t currP = indexGZ;

            while (currN > 0 && currP < N)
            {
                if (nums[currN - 1] > nums[currP])
                {
                    result[i++] = nums[currP];
                    ++currP;
                }
                else
                {
                    result[i++] = nums[currN - 1];
                    --currN;
                }
            }

            while (currN > 0)
            {
                result[i++] = nums[currN - 1];
                --currN;
            }
            while (currP < N)
                result[i++] = nums[currP++];

            return result;
        }
    };
}
