#pragma once

#include <bitset>
#include <string>
#include <vector>

namespace p60
{
    class Solution
    {
      public:
        std::string getPermutation(int n, int k)
        {
            --k;

            std::bitset<9> used = {};
            std::vector<int> generated;
            generated.reserve(n);

            for (int curr = 0; curr < n; ++curr)
            {
                auto [q, r] = lldiv(k, fac(n - 1 - curr));

                for (int u = 0; u < n; ++u)
                {
                    if (!used[size_t(u)])
                        --q;
                    if (-1 == q)
                    {
                        generated.push_back(u);
                        used[u] = true;
                        break;
                    }
                }

                k = int(r);
            }

            std::string result;
            result.reserve(generated.size());
            for (auto g : generated)
            {
                result.push_back('1' + g);
            }

            return result;
        }

      private:
        int fac(int n)
        {
            switch (n)
            {
            case 0:
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 6;
            case 4:
                return 24;
            case 5:
                return 120;
            case 6:
                return 720;
            case 7:
                return 5040;
            case 8:
                return 40320;
            case 9:
                return 362880;
            }

            return n * fac(n - 1);
        }
    };
}
