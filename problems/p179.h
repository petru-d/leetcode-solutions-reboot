#pragma once
#include <functional>
#include <string>
#include <vector>

namespace p179
{
    class Solution
    {
      public:
        bool lessstr(const std::string& l, const std::string& r)
        {
            size_t L = l.size();
            size_t R = r.size();

            size_t N = std::min(L, R);
            for (size_t i = 0; i < N; ++i)
            {
                if (l[i] < r[i])
                    return true;
                if (l[i] > r[i])
                    return false;
            }

            if (L == R)
                return false;

            // identical up to the end of the shortest one

            if (L < R)
                // l is a prefix of r
                // so we are comparing
                // l to ls (s is the suffix of r)
                // so, what's first
                // lls or lsl ?
                // since l is the same in both, we're comparing
                // ls (which is r) to sl
                for (size_t i = 0; i < R; ++i)
                {
                    if (r[i] < r[(i + L) % R])
                        return true;
                    if (r[i] > r[(i + L) % R])
                        return false;
                }
            else
                // r is a prefix of l
                // so we are comparing
                // rs to r (s is the suffix of l)
                // so, what's first
                // rsr or rrs ?
                // since r is the same in both, we're comparing
                // sr to rs (which is l)
                for (size_t i = 0; i < L; ++i)
                {
                    if (l[(i + R) % L] < l[i])
                        return true;
                    if (l[(i + R) % L] > l[i])
                        return false;
                }

            // being here means that we have something like
            // 123 and 123123 - doesn't matter which is first, but to keep a good ordering, we need to choose
            return L < R;
        }

        std::string largestNumber(std::vector<int>& nums)
        {
            size_t N = nums.size();
            std::vector<std::string> nums_str(N, "");

            bool found_non_zero = false;

            size_t final_count = 0;
            for (size_t i = 0; i < N; ++i)
            {
                found_non_zero |= (nums[i] != 0);
                nums_str[i] = std::to_string(nums[i]);
                final_count += nums_str[i].size();
            }
            if (!found_non_zero)
                return "0";

            std::sort(nums_str.rbegin(), nums_str.rend(),
                      std::bind(&Solution::lessstr, this, std::placeholders::_1, std::placeholders::_2));

            std::string result;
            result.reserve(final_count);
            for (const auto& n : nums_str)
                result.append(n);

            return result;
        }
    };
}
