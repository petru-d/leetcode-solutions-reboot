#pragma once

namespace p526
{
    class Solution
    {
      public:
        int countArrangement(int n)
        {
            std::vector<int> sol(size_t(n), 0);
            int total = 0;
            go(n, sol, 0, total);
            return total;
        }

        void go(int n, std::vector<int>& sol, size_t count, int& total)
        {
            if (count == size_t(n))
            {
                ++total;
                return;
            }

            auto acceptable = [&](int i) {
                if ((count + 1) % i != 0 && i % (count + 1) != 0)
                    return false;
                for (size_t x = 0; x < count; ++x)
                    if (sol[x] == i)
                        return false;

                return true;
            };

            for (int i = n; i >= 1; --i)
            {
                if (acceptable(i))
                {
                    sol[count] = i;
                    go(n, sol, count + 1, total);
                }
            }
        }
    };
}
