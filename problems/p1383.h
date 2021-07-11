#pragma once
#include <algorithm>
#include <queue>
#include <vector>

namespace p1383
{
    class Solution
    {
      public:
        int maxPerformance(int n, std::vector<int>& speed, std::vector<int>& efficiency, int k)
        {
            auto N = size_t(n);
            auto K = size_t(k);
            int modulo = 1000000007;

            struct Candidate
            {
                int speed = 0;
                int efficiency = 0;
                Candidate(int s, int e) : speed(s), efficiency(e)
                {
                }
            };

            std::vector<Candidate> candidates;
            candidates.reserve(N);
            for (size_t i = 0; i < N; ++i)
                candidates.emplace_back(speed[i], efficiency[i]);

            std::sort(candidates.begin(), candidates.end(),
                      [](const Candidate& l, const Candidate& r) { return l.efficiency > r.efficiency; });

            std::priority_queue<int, std::vector<int>, std::greater<int>> q;

            uint64_t curr_sum = 0;
            uint64_t best_sum = 0;

            for (const auto& c : candidates)
            {
                q.push(c.speed);
                curr_sum += c.speed;
                if (q.size() > K)
                {
                    auto t = q.top();
                    curr_sum -= t;
                    q.pop();
                }

                best_sum = std::max(best_sum, c.efficiency * curr_sum);
            }

            return int(best_sum % modulo);
        }
    };
}
