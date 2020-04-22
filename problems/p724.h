#pragma once
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace p724
{
    class Solution
    {
      public:
        // int pivotIndex(std::vector<int>& nums)
        //{
        //    // maps partial sums [0..k) to the indices where they occur.
        //    std::unordered_map<int, std::unordered_set<size_t>> partial_sum_to_indices;
        //    partial_sum_to_indices[0] = {0};

        //    int curr_sum = 0;
        //    size_t N = nums.size();
        //    for (size_t i = 0; i < N; ++i)
        //    {
        //        curr_sum += nums[i];
        //        partial_sum_to_indices[curr_sum].insert(i + 1);
        //    }

        //    size_t left_most_pivot = std::numeric_limits<size_t>::max();
        //    // traverse backwards, keeping the current sum. look in the partial sums for it. if the index fits, we have a
        //    // solution.
        //    int curr_sum_back = 0;
        //    for (size_t i = N; i >= 1; --i)
        //    {
        //        auto pos = partial_sum_to_indices.find(curr_sum_back);
        //        if (pos != partial_sum_to_indices.end())
        //        {
        //            const auto& indices = pos->second;

        //            if (0 != indices.count(i - 1))
        //                left_most_pivot = std::min(left_most_pivot, i - 1);
        //        }

        //        curr_sum_back += nums[i - 1];
        //    }
        //    return left_most_pivot == std::numeric_limits<size_t>::max() ? -1 : static_cast<int>(left_most_pivot);
        //}

        // int pivotIndex(std::vector<int>& nums)
        //{
        //    // keep partial_sums[i] = sum[nums[0]... nums[i-1])
        //    size_t N = nums.size();
        //    std::vector<int> partial_sums(N, 0);

        //    int curr_sum = 0;
        //    for (size_t i = 1; i < N; ++i)
        //    {
        //        curr_sum += nums[i - 1];
        //        partial_sums[i] = curr_sum;
        //    }

        //    size_t left_most_pivot = std::numeric_limits<size_t>::max();
        //    // traverse backwards, keeping the current sum.
        //    // test if nums[i - 1] is a pivot
        //    int curr_sum_back = 0;
        //    for (size_t i = N; i >= 1; --i)
        //    {
        //        if (partial_sums[i - 1] == curr_sum_back)
        //            left_most_pivot = std::min(left_most_pivot, i - 1);
        //        curr_sum_back += nums[i - 1];
        //    }
        //    return left_most_pivot == std::numeric_limits<size_t>::max() ? -1 : static_cast<int>(left_most_pivot);
        //}

        int pivotIndex(std::vector<int>& nums)
        {
            if (nums.empty())
                return -1;

            int total = std::accumulate(nums.begin(), nums.end(), 0);
            if (total - nums[0] == 0)
                return 0;

            int left = 0;
            int right = -1; // silence clang

            size_t N = nums.size();
            for (size_t i = 1; i < N; ++i)
            {
                left += nums[i - 1];
                right = total - left - nums[i];

                if (left == right)
                    return static_cast<int>(i);
            }

            return -1;
        }

        // yet another solution: keep the partial sums in an array
        // to check if i is a pivot index, see if the partial sum to its left is exactly half of the total - nums[i]
    };
}