#pragma once
#include <vector>

namespace p645
{
    class Solution
    {
      public:
        std::vector<int> findErrorNumsMine(std::vector<int>& nums)
        {
            std::vector<int> dup_detect(nums.size(), 0);

            int n = int(nums.size());

            int k = 0;

            int sum = 0;
            for (int i = 1; i <= n; ++i)
            {
                sum += nums[i - 1];
                if (dup_detect[nums[i - 1] - 1] != 0)
                    k = nums[i - 1];
                dup_detect[nums[i - 1] - 1] = nums[i - 1];
            }

            int j = k - sum + n * (n + 1) / 2;

            return {k, j};
        }

        std::vector<int> findErrorNumsleetcode(std::vector<int>& nums)
        {
            int n = int(nums.size());

            // xor all this:
            // 1 2 .. x .. y .. n (initial set)
            // 1 2 .. x .. x .. n (error set)
            // all_xor is now x ^ y (x is repating, y is missing)
            int all_xor = 0;
            for (int i = 1; i <= n; ++i)
                all_xor = all_xor ^ i ^ nums[i - 1];

            int diff_bit = all_xor & ~(all_xor - 1);
            // or for (int i = 0; i < 32; ++i) if (all_xor & 1 << i) diff_bit = 1 << i;

            // xor only stuff that shares a bit with diff_bit
            // this might either be some duplicates and 3 times x, which makes x
            // or some duplicates and 1 times y which makes y

            int share_diff_bit = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (i & diff_bit)
                    share_diff_bit = share_diff_bit ^ i;
                if (nums[i - 1] & diff_bit)
                    share_diff_bit = share_diff_bit ^ nums[i - 1];
            }

            // now share_diff_bit is either x or y
            // which means share_diff_bit ^ x ^ y (x^y == all_xor) is either y or x

            int x_or_y = share_diff_bit;
            int y_or_x = share_diff_bit ^ all_xor;

            for (int i = 1; i <= n; ++i)
            {
                if (nums[i] == x_or_y)
                {
                    return {x_or_y, y_or_x};
                }
                if (nums[i] == y_or_x)
                {
                    return {y_or_x, x_or_y};
                }
            }
            return {-1, -1};
        }
    };

}
