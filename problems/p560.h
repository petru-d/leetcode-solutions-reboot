#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace p560
{
    class Solution
    {
      public:
        // int subarraySum(std::vector<int>& nums, int k)
        //{
        //    int result = 0;
        //    // sums[s] = {i1, i2.. ik} means that sum[0, i1) = sum[0, i2) = sum[0, ik) = s
        //    std::unordered_map<int, std::unordered_set<size_t>> sums;

        //    sums[0] = {0};

        //    int curr_sum = 0;
        //    size_t N = nums.size();
        //    for (size_t i = 0; i < N; ++i)
        //    {
        //        curr_sum += nums[i];

        //        // search for curr_sum - k
        //        auto pos = sums.find(curr_sum - k);
        //        if (pos != sums.end())
        //            result += static_cast<int>(pos->second.size());

        //        // update our data structure (after checking, to avoid empty intervals)
        //        sums[curr_sum].insert(i + 1);
        //    }

        //    return result;
        //}

        // optimized implementation - we don't need the intervals, only their number
        int subarraySum(std::vector<int>& nums, int k)
        {
            int result = 0;
            // sums[s] = k means that exist {i1, i2, ..., ik} such that sum[0, i1) = sum[0, i2) = sum[0, ik) = s
            std::unordered_map<int, size_t> sums;

            // the interval [0, 0) has sum 0
            sums[0] = 1;

            int curr_sum = 0;
            size_t N = nums.size();
            for (size_t i = 0; i < N; ++i)
            {
                curr_sum += nums[i];

                // search for curr_sum - k
                auto pos = sums.find(curr_sum - k);
                if (pos != sums.end())
                    result += static_cast<int>(pos->second);

                // update our data structure (after checking, to avoid empty intervals)
                ++sums[curr_sum];
            }

            return result;
        }
    };
}