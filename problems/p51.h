#pragma once

#include <string>
#include <vector>

namespace p51
{
    class Solution
    {
      public:
        std::vector<std::vector<std::string>> solveNQueens(int n)
        {
            std::vector<int> partial_sol = {};

            solve(n, partial_sol);

            return format(n, _solutions);
        }

      private:
        std::vector<std::vector<int>> _solutions;

        void solve(int n, std::vector<int>& partial_sol)
        {
            if (partial_sol.size() == size_t(n))
            {
                _solutions.push_back(partial_sol);
                return;
            }

            for (int i = 0; i < n; ++i)
            {
                if (can_append(i, partial_sol))
                {
                    partial_sol.push_back(i);
                    solve(n, partial_sol);
                    partial_sol.pop_back();
                }
            }
        }

        bool can_append(int x, const std::vector<int>& partial_sol)
        {
            // check columns
            for (auto p : partial_sol)
                if (x == p)
                    return false;

            // current position is (partial_sol.size(), x)
            // test if it is on a diagonal with an existing point (i, partial_sol[i])
            for (int i = 0; i < int(partial_sol.size()); ++i)
                if ((int(partial_sol.size()) - i == x - partial_sol[i]) || (int(partial_sol.size()) - i == partial_sol[i] - x))
                    return false;

            return true;
        }

        std::vector<std::vector<std::string>> format(int n, const std::vector<std::vector<int>>& solutions)
        {
            std::vector<std::vector<std::string>> result;
            for (const auto& sol : solutions)
            {
                std::vector<std::string> res;
                for (int s : sol)
                {
                    std::string res_line(s, '.');
                    res_line.append(1, 'Q');
                    res_line.append(size_t(n) - s - 1, '.');
                    res.push_back(std::move(res_line));
                }
                result.push_back(std::move(res));
            }
            return result;
        }
    };

    class Solution2
    {
      public:
        std::vector<std::vector<std::string>> solveNQueens(int n)
        {
            size_t N = size_t(n);

            std::vector<size_t> curr;
            std::vector<size_t> taken(N, 0);

            go(N, curr, taken);

            std::vector<std::vector<std::string>> res;
            for (const auto& s : sol)
            {
                std::vector<std::string> curr;
                curr.reserve(N);
                for (auto i : s)
                {
                    std::string line;
                    line.reserve(N);
                    line.append(i, '.');
                    line.append(1, 'Q');
                    line.append(N - i - 1, '.');
                    curr.push_back(std::move(line));
                }
                res.push_back(std::move(curr));
            }

            return res;
        }

        void go(size_t N, std::vector<size_t>& curr, std::vector<size_t>& taken)
        {
            if (curr.size() == N)
            {
                sol.push_back(curr);
                return;
            }

            auto diag_conflict = [&](size_t Y) {
                auto C = curr.size();
                for (size_t i = 0; i < C; ++i)
                    if (C - i == Y - curr[i] || C - i == curr[i] - Y)
                        return true;

                return false;
            };

            for (size_t i = 0; i < N; ++i)
            {
                if (taken[i] == 1 || diag_conflict(i))
                    continue;
                curr.push_back(i);
                taken[i] = 1;
                go(N, curr, taken);
                curr.pop_back();
                taken[i] = 0;
            }
        }

        std::vector<std::vector<size_t>> sol;
    };
}
