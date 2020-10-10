#pragma once
#include <vector>

namespace p39
{
    // class Solution
    //{
    //  public:
    //    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
    //    {
    //        std::sort(candidates.begin(), candidates.end());

    //        std::vector<std::vector<std::vector<int>>> solutions(size_t(target) + 1, std::vector<std::vector<int>>{});
    //        solutions[0].push_back({});

    //        for (auto c : candidates)
    //        {
    //            for (int curr_t = c; curr_t <= target; ++curr_t)
    //            {
    //                auto sols_prev = solutions[size_t(curr_t) - c];
    //                for (auto& sp : sols_prev)
    //                    sp.push_back(c);

    //                for (auto&& sp : sols_prev)
    //                {
    //                    solutions[size_t(curr_t)].push_back(std::move(sp));
    //                }
    //            }
    //        }

    //        return solutions[target];
    //    }
    //};

    class Solution
    {
      public:
        std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
        {
            std::sort(candidates.begin(), candidates.end());

            std::vector<int> r;
            std::vector<std::vector<int>> res;
            findNumbers(candidates, target, res, r, 0);
            return res;
        }
        void findNumbers(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& res, std::vector<int>& r, int i)
        {
            if (target == 0)
            {
                res.push_back(r);
                return;
            }
            while (i < candidates.size() && target - candidates[i] >= 0)
            {
                r.push_back(candidates[i]);
                findNumbers(candidates, target - candidates[i], res, r, i);
                i++;
                r.pop_back();
            }
        }
    };
}