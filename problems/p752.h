#pragma once
#include <string>
#include <vector>

namespace p752
{
    class Solution
    {
      public:
        int openLock(std::vector<std::string>& deadends, std::string target)
        {
            std::array<uint8_t, 10000> dead = {};
            for (const auto& d : deadends)
                dead[size_t(std::stoi(d))] = 1;
            if (dead[0] == 1)
                return -1;

            auto targ = size_t(std::stoi(target));

            std::array<uint8_t, 10000> visited = {};

            std::vector<size_t> q;
            q.push_back(0);
            visited[0] = 1;
            int steps = 0;
            while (!q.empty())
            {
                std::vector<size_t> new_q;

                auto sz = q.size();
                for (size_t i = 0; i < sz; ++i)
                {
                    auto n = q[i];
                    if (n == targ)
                        return steps;

                    auto neibs = get_neibs(n);
                    for (auto neib : neibs)
                        if (!dead[neib] && !visited[neib])
                        {
                            new_q.push_back(neib);
                            visited[neib] = 1;
                        }
                }

                ++steps;
                q = std::move(new_q);
            }

            return -1;
        }

      private:
        std::array<std::array<size_t, 8>, 10000> neibs = {};
        std::array<uint8_t, 10000> have_neibs = {};

        const std::array<size_t, 8>& get_neibs(size_t node)
        {
            if (have_neibs[node])
                return neibs[node];

            auto curr_n = node;
            std::array<size_t, 8> node_neibs;

            auto pow = 1;
            for (size_t i = 0; i < 4; ++i)
            {
                auto [q, r] = std::div(curr_n, 10);

                // replace i'th digit (from end) with
                // (r + 1) % 10 and (r + 9) % 10
                auto zero_ith = node - pow * r;
                auto n1 = zero_ith + pow * ((r + 1) % 10);
                auto n2 = zero_ith + pow * ((r + 9) % 10);

                node_neibs[2 * i] = n1;
                node_neibs[2 * i + 1] = n2;

                pow *= 10;
                curr_n = q;
            }

            neibs[node] = node_neibs;
            have_neibs[node] = 1;
            return neibs[node];
        };
    };

}
