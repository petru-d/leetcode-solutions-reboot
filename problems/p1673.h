#pragma once
#include <vector>
#include <stack>

namespace p1673
{
    class Solution
    {
      public:
        std::vector<int> mostCompetitive(std::vector<int>& nums, int k)
        {
            std::vector<int> seq(k, 0);
            size_t q = 1;
            seq[0] = nums[0];

            size_t N = nums.size();
            for (size_t i = 1; i < N; ++i)
            {
                if (nums[i] >= nums[i - 1])
                {
                    if (q < k)
                        seq[q++] = nums[i];
                    continue;
                }

                // including the current, we have N - i numbers left

                size_t start = N - i >= k ? 0 : k + i - N;
                bool added = false;
                for (size_t j = start; j < q; ++j)
                    if (seq[j] > nums[i])
                    {
                        added = true;
                        seq[j] = nums[i];
                        q = j + 1;
                        break;
                    }

                if (!added && q < k)
                {
                    seq[q++] = nums[i];
                }
            }

            return seq;
        }

        std::vector<int> mostCompetitive2(std::vector<int>& nums, int k)
        {
            size_t N = nums.size();
            size_t can_drop = N - k;

            std::vector<int> seq(N, 0);
            size_t q = 0;

            for (size_t i = 0; i < N; ++i)
            {
                while (q > 0 && can_drop > 0 && seq[q - 1] > nums[i])
                {
                    --q;
                    --can_drop;
                }
                seq[q++] = nums[i];
            }

            std::vector<int> result;
            result.reserve(k);
            for (size_t i = 0; i < k; ++i)
                result.push_back(seq[i]);

            return result;
        }

        std::vector<int> mostCompetitive3(std::vector<int>& nums, int k)
        {
            std::stack<int> to_process;
            for (int i = 0; i < size(nums); ++i)
            {
                while (!empty(to_process) && to_process.top() > nums[i] && size(to_process) + size(nums) - i > k)
                {
                    to_process.pop();
                }
                if (size(to_process) < k)
                    to_process.emplace(nums[i]);
            }

            std::vector<int> output(k);
            for (int i = k - 1; i >= 0; --i)
            {
                output[i] = to_process.top();
                to_process.pop();
            }
            return output;
        }
    };
}
