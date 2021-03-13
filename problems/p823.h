#pragma once
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <unordered_map>
#include <vector>

namespace p823
{
    class Solution
    {
      public:
        int addmod(int a, int b)
        {
            return ((a % 1000000007) + (b % 1000000007)) % 1000000007;
        }
        int mulmod(int a, int b)
        {
            return int((uint64_t(a % 1000000007) * (b % 1000000007)) % 1000000007);
        }

        // for a number, the pairs of factors and the solution
        struct Data
        {
            std::vector<std::pair<int, int>> Factors;
            int Sol = 0;
        };

        int numFactoredBinaryTrees(std::vector<int>& arr)
        {
            auto A = arr.size();
            if (A <= 1)
                return int(A);

            std::sort(arr.begin(), arr.end());

            std::unordered_map<int, Data> sol;
            sol[arr[0]] = Data{{}, 1};

            for (size_t i = 1; i < A; ++i)
            {
                auto [posi, ok] = sol.insert({arr[i], {}});
                for (size_t j = 0; j < i; ++j)
                {
                    if (arr[j] > sqrt(arr[i]))
                        break;
                    if (arr[i] % arr[j] != 0)
                        continue;
                    auto k = arr[i] / arr[j];
                    auto posk = sol.find(k);
                    if (posk == sol.end())
                        continue;
                    posi->second.Factors.push_back({arr[j], k});
                }
            }

            int result = 0;
            for (const auto& [k, v] : sol)
                result = addmod(result, get_sol(k, sol));
            ;

            // for (const auto& [k, v] : sol)
            // {
            //     cout << k << endl;
            //     cout << "{";
            //     for (const auto& [f1, f2] : v.Factors)
            //         cout << "(" << f1 << " " << f2 << ")";
            //     cout << "}" << endl;
            //     cout << v.Sol << endl << endl;
            // }

            return result;
        }

        int get_sol(int n, std::unordered_map<int, Data>& sol)
        {
            auto& data_n = sol.find(n)->second;
            if (data_n.Sol != 0)
                return data_n.Sol;

            int result = 1;
            for (const auto& [f1, f2] : data_n.Factors)
            {
                int mult = f1 != f2 ? 2 : 1;
                int forcurrfactos = mulmod(mulmod(mult, get_sol(f1, sol)), get_sol(f2, sol));
                result = addmod(result, forcurrfactos);
            }

            data_n.Sol = result;
            return result;
        }
    };
}
