#pragma once
#include <algorithm>
#include <iomanip>
#include <ostream>
#include <vector>

namespace p134
{
    struct Trip
    {
        int low = std::numeric_limits<int>::max();
        int sum_gas = 0;
        int sum_cost = 0;
    };

    class Solution
    {

      public:
        int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
        {
            auto t0 = make_trip(gas, cost, 0);
            int low = t0.low;

            if (low >= 0)
                return 0;
            if (t0.sum_gas < t0.sum_cost)
                return -1;

            for (size_t i = 1; i < gas.size(); ++i)
            {
                low -= (gas[i - 1] - cost[i - 1]);
                if (low >= 0)
                    return int(i);
            }

            return -1;
        }

      private:
        Trip make_trip(const std::vector<int>& gas, const std::vector<int>& cost, size_t pos)
        {
            Trip result;

            size_t N = gas.size();

            int after_fill = gas[pos];
            int arrive = 0;
            result.sum_gas = gas[pos];
            result.sum_cost = cost[pos];
            for (size_t i = 1; i <= N; ++i)
            {
                arrive = after_fill - cost[(pos + i - 1) % N];

                result.low = std::min(result.low, arrive);
                if (i != N)
                {
                    after_fill = arrive + gas[(pos + i) % N];
                    result.sum_gas += gas[(pos + i) % N];
                    result.sum_cost += cost[(pos + i) % N];
                }
            }

            return result;
        }
    };
}
