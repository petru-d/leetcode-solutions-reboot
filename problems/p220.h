#pragma once

#include <algorithm>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>

namespace p220
{
    class Solution
    {
      public:
        // sliding window
        bool containsNearbyAlmostDuplicate_sliding_window(std::vector<int>& nums, int k, int t)
        {
            size_t n = nums.size();

            std::vector<size_t> indices(n, 0);
            std::iota(indices.begin(), indices.end(), 0);
            std::sort(indices.begin(), indices.end(), [&nums](size_t l, size_t r) { return nums[l] < nums[r]; });

            size_t left = 0;
            size_t right = 1;
            while (right < n)
            {

                auto i1 = int64_t(indices[left]);
                auto i2 = int64_t(indices[right]);

                auto n1 = int64_t(nums[indices[left]]);
                auto n2 = int64_t(nums[indices[right]]);

                if (abs(i1 - i2) <= k && abs(n1 - n2) <= t)
                    return true;

                // we went too far apart with the indices - check next number
                if (abs(i1 - i2) > k)
                    ++right;

                // the numbers are too far apart - shrink the window until we are back in range
                if (abs(n1 - n2) > t)
                    ++left;

                if (left == right)
                    ++right;
            }

            return false;
        }

        // using buckets (best approach)
        bool containsNearbyAlmostDuplicate_buckets(std::vector<int>& nums, int k, int t)
        {
            size_t n = nums.size();

            if (n == 0 || k <= 0 || t < 0)
                return false;

            auto get_bucket = [t](int num) {
                int bucket = num / ((long)t + 1);
                // For negative numbers, we need to decrement bucket by 1
                // to ensure floor division.
                // For example, -1/2 = 0 but -1 should be put in Bucket[-1].
                // Therefore, decrement by 1.
                if (num < 0)
                    --bucket;

                return bucket;
            };

            std::unordered_map<int, int> buckets;

            for (size_t i = 0; i < n; ++i)
            {
                int bucket = get_bucket(nums[i]);

                if (buckets.find(bucket) != buckets.end())
                    return true;

                buckets[bucket] = nums[i];
                if (buckets.find(bucket - 1) != buckets.end() && (long)nums[i] - buckets[bucket - 1] <= t)
                    return true;
                if (buckets.find(bucket + 1) != buckets.end() && (long)buckets[bucket + 1] - nums[i] <= t)
                    return true;

                // if there was any collision, we would have returned true - so no collision
                // so having a bucket size greater than k (without collision) means we checked exactly k + 1 numbers
                // which means we need to discard the number at position i-k (sliding window).
                if (buckets.size() > k)
                {
                    int key_to_remove = get_bucket(nums[size_t(i) - k]);
                    buckets.erase(key_to_remove);
                }
            }

            return false;
        }

        // ugly and slow, but my solution
        bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
        {
            size_t N = nums.size();
            if (N <= 1 || k <= 0 || t < 0)
                return false;

            size_t K = size_t(k);

            std::map<int, size_t> next_k;
            for (size_t i = 0; i < K && i < N - 1; ++i)
            {
                insert_one(next_k, nums[i]);
                if (close_enough(nums[std::min(i + 1, N - 1)], next_k, t))
                    return true;
            }
            // includes the k elements before
            std::pair<size_t, size_t> window = {0, K};

            for (size_t i = K + 1; i < N; ++i)
            {
                std::pair<size_t, size_t> new_window;
                new_window.first = window.first + 1;
                new_window.second = window.second + 1;

                erase_one(next_k, nums[window.first]);
                insert_one(next_k, nums[new_window.second - 1]);

                if (close_enough(nums[i], next_k, t))
                    return true;

                window = new_window;
            }

            return false;
        }

      private:
        bool close_enough(int n, std::map<int, size_t>& next_k, int max_diff)
        {
            if (next_k.empty())
                return false;

            auto [low, hi] = next_k.equal_range(n);

            if (low != hi)
                return std::abs(int64_t(low->first) - int64_t(n)) <= int64_t(max_diff);

            if (low != next_k.begin() && std::abs(int64_t(std::prev(low)->first) - int64_t(n)) <= int64_t(max_diff))
                return true;

            if (low != next_k.end() && std::abs(int64_t(low->first) - int64_t(n)) <= int64_t(max_diff))
            {
                return true;
            }

            if (low != next_k.end() && std::next(low) != next_k.end() &&
                std::abs(int64_t(std::next(low)->first) - int64_t(n)) <= int64_t(max_diff))
                return true;

            return false;

            /*if (low == next_k.end() && std::abs(int64_t(next_k.begin()->first) - int64_t(n)) <= int64_t(max_diff))
                return true;
            if (low != next_k.end() && std::abs(int64_t(low->first) - int64_t(n)) <= int64_t(max_diff))
                return true;
            if (hi == next_k.end() && std::abs(int64_t(next_k.rbegin()->first) - int64_t(n)) <= int64_t(max_diff))
                return true;
            if (hi != next_k.end() && std::abs(int64_t(hi->first) - int64_t(n)) <= int64_t(max_diff))
                return true;*/

            return false;
        }

        void insert_one(std::map<int, size_t>& next_k, int target)
        {
            ++next_k[target];
        }

        void erase_one(std::map<int, size_t>& next_k, int target)
        {
            auto itr = next_k.find(target);
            if (itr != next_k.end())
            {
                if (itr->second == 1)
                    next_k.erase(itr);
                else
                    --itr->second;
            }
        }
    };
}
