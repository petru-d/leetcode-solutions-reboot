#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace p128
{
    class Solution3
    {
      public:
        int longestConsecutive(std::vector<int>& nums)
        {
            struct Bucket
            {
                int Min = -1;
                int Max = -1;
            };

            std::unordered_map<int, Bucket*> buckets;
            std::unordered_set<int> saw;

            for (auto n : nums)
            {
                auto sawIt = saw.find(n);
                if (sawIt != saw.end())
                    continue;
                saw.insert(n);

                auto posUp = buckets.find(n + 1);
                auto posDown = buckets.find(n - 1);

                if (posUp == buckets.end() && posDown == buckets.end())
                {
                    buckets[n] = new Bucket{n, n};
                }
                else if (posUp != buckets.end() && posDown == buckets.end())
                {
                    auto* bucket = posUp->second;
                    --bucket->Min;
                    buckets[n] = bucket;

                    if (n + 1 != bucket->Max)
                        buckets.erase(n + 1);
                }
                else if (posUp == buckets.end() && posDown != buckets.end())
                {
                    auto* bucket = posDown->second;
                    ++bucket->Max;
                    buckets[n] = bucket;

                    if (n - 1 != bucket->Min)
                        buckets.erase(n - 1);
                }
                else
                {
                    auto* upBucket = posUp->second;
                    auto* downBucket = posDown->second;
                    downBucket->Max = upBucket->Max;
                    delete upBucket;
                    buckets[downBucket->Max] = downBucket;

                    if (n - 1 != downBucket->Min)
                        buckets.erase(n - 1);
                    if (n + 1 != downBucket->Max)
                        buckets.erase(n + 1);
                }
            }

            int best = 0;
            for (const auto& [k, v] : buckets)
            {
                best = std::max(best, 1 + v->Max - v->Min);
            }

            return best;
        }
    };

    class Solution2
    {
      public:
        int longestConsecutive(std::vector<int>& nums)
        {
            std::sort(nums.begin(), nums.end());

            auto N = nums.size();

            size_t seq_start = 0;
            size_t best = 0;
            for (size_t i = 1; i < N; ++i)
            {
                if (nums[i] == 1 + nums[i - 1])
                    continue;
                if (nums[i] == nums[i - 1])
                {
                    ++seq_start;
                    continue;
                }

                best = std::max(best, i - seq_start);
                seq_start = i;
            }

            best = std::max(best, N - seq_start);

            return int(best);
        }
    };

    class Solution4
    {
      public:
        int longestConsecutive(std::vector<int>& nums)
        {
            std::unordered_set<int> s;
            for (const auto n : nums)
                s.insert(n);

            int best_streak = 0;
            for (const auto ss : s)
            {
                // only consider elements that are the start of a sequence
                auto pos_prev = s.find(ss - 1);
                if (pos_prev != s.end())
                    continue;

                int curr_streak = 1;
                int curr = ss;
                while (true)
                {
                    auto pos = s.find(++curr);
                    if (pos == s.end())
                        break;
                    ++curr_streak;
                }

                best_streak = std::max(best_streak, curr_streak);
            }

            return best_streak;
        }
    };

    // copied to check if they increased testcases
    class Solution
    {
      public:
        int longestConsecutive(std::vector<int>& nums)
        {
            std::unordered_set<int> num_set;
            for (int num : nums)
            {
                num_set.insert(num);
            }

            int longestStreak = 0;

            for (int num : num_set)
            {
                if (!(num_set.find(num - 1) != num_set.end()))
                {
                    int currentNum = num;
                    int currentStreak = 1;

                    while (num_set.find(currentNum + 1) != num_set.end())
                    {
                        currentNum += 1;
                        currentStreak += 1;
                    }
                    longestStreak = currentStreak > longestStreak ? currentStreak : longestStreak;
                }
            }

            return longestStreak;
        }
    };

}
