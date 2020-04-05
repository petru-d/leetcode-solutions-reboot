#pragma once
#include <algorithm>
#include <set>
#include <vector>

namespace p47
{
    // I think this is a dead end when it comes to optimization - I can't find a way to completely the need for the set of raw
    // solutions.

    // From lc site, i saw that using a swap based technique would work better (e.g. keeping a swap history will fix all
    // duplicates).

    class Solution
    {
      public:
        std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
        {
            if (nums.empty())
                return {};

            std::sort(nums.begin(), nums.end());

            std::vector<int> curr = {nums[0]};
            backtrack(nums, curr);

            std::vector<std::vector<int>> result;
            std::copy(_solutionsRaw.begin(), _solutionsRaw.end(), std::back_inserter(result));
            return result;
        }

      private:
        void backtrack(const std::vector<int>& nums, const std::vector<int>& curr)
        {
            if (curr.size() == nums.size())
            {
                _solutionsRaw.insert(curr);
                return;
            }
            for (size_t c = 0; c <= curr.size(); ++c)
            {

                // insert nums[curr.size()] in positions 0, 1, ... curr.size() into curr, continue from there.
                // however, don't insert at the right of an identical element (helps with (but doesn't completely fix)
                // duplication)

                auto to_insert = nums[curr.size()];

                if (c != 0 && curr[c - 1] == to_insert)
                    continue;

                std::vector<int> newCurr;
                newCurr.reserve(curr.size() + 1);

                std::copy(curr.begin(), curr.begin() + c, std::back_inserter(newCurr));
                newCurr.push_back(to_insert);
                std::copy(curr.begin() + c, curr.end(), std::back_inserter(newCurr));

                backtrack(nums, newCurr);
            }
        }

        std::set<std::vector<int>> _solutionsRaw;
    };
}