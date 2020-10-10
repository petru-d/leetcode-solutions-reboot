#pragma once
#include <vector>

namespace p495
{
    class Solution
    {
      public:
        int findPoisonedDuration(std::vector<int>& timeSeries, int duration)
        {
            size_t N = timeSeries.size();
            if (N == 0)
                return 0;

            int totalPoison = 0;

            int poisonStart = timeSeries[0];
            int poisonEnd = timeSeries[0] + duration;

            for (size_t i = 1; i < N; ++i)
            {
                if (timeSeries[i] < poisonEnd)
                    poisonEnd = timeSeries[i] + duration;
                else
                {
                    totalPoison += poisonEnd - poisonStart;
                    poisonStart = timeSeries[i];
                    poisonEnd = timeSeries[i] + duration;
                }
            }
            totalPoison += poisonEnd - poisonStart;

            return totalPoison;
        }
    };
}
