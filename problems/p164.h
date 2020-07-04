#pragma once
#include <algorithm>
#include <vector>
namespace p164
{
    class Solution
    {
        class Bucket
        {
            int _min = std::numeric_limits<int>::max();
            int _max = std::numeric_limits<int>::min();

          public:
            void Add(int m)
            {
                _min = std::min(_min, m);
                _max = std::max(_max, m);
            }
            bool Used() const
            {
                return _min != std::numeric_limits<int>::max();
            }
            int Min() const
            {
                return _min;
            }
            int Max() const
            {
                return _max;
            }
        };

      public:
        int maximumGap(std::vector<int>& nums)
        {
            if (nums.size() <= 1)
                return 0;

            // max gap >= (max - min) / (count - 1) = GM

            // put all numbers in buckets of size GM.
            //    Bucket 0 contains numbers from [min, min + GM), Bucket 1 contains numbers from [min + GM, min + 2*GM) etc
            //    we will have (max - min) / GM + 1 buckets
            // Then find the max distance between each bucket's max and the next one's min
            //    This is our max gap, since inside a bucket the distance is smaller than the minimal value for the max gap

            const auto [minit, maxit] = std::minmax_element(nums.begin(), nums.end());
            const auto mini = *minit;
            const auto maxi = *maxit;

            if (mini == maxi)
                return 0;

            const auto GM = std::max(size_t(1), (size_t(maxi) - mini) / (nums.size() - 1));
            std::vector<Bucket> buckets((size_t(maxi) - mini) / GM + 1);

            for (const auto& n : nums)
            {
                buckets[(size_t(n) - mini) / GM].Add(n);
            }

            int max_gap = 1;

            int prev_bucket_max = mini;
            for (const auto& b : buckets)
            {
                if (!b.Used())
                    continue;

                max_gap = std::max(max_gap, b.Min() - prev_bucket_max);
                prev_bucket_max = b.Max();
            }

            return max_gap;
        }
    };
}
