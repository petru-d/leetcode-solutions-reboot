#pragma once

namespace p229
{
    class Solution
    {
      public:
        std::vector<int> majorityElement(std::vector<int>& nums)
        {
            struct Candidate
            {
                int Number = 0;
                size_t Occurences = 0;
            };

            Candidate first;
            Candidate second;

            for (const auto& n : nums)
            {
                if (first.Number == n && first.Occurences != 0)
                {
                    ++first.Occurences;
                }
                else if (second.Number == n && second.Occurences != 0)
                {
                    ++second.Occurences;
                }
                else if (first.Occurences == 0)
                {
                    first.Number = n;
                    first.Occurences = 1;
                }
                else if (second.Occurences == 0)
                {
                    second.Number = n;
                    second.Occurences = 1;
                }
                else
                {
                    --first.Occurences;
                    --second.Occurences;
                }
            }

            size_t first_count = (first.Occurences > 0) ? std::count(nums.begin(), nums.end(), first.Number) : 0;
            size_t second_count = (second.Occurences > 0) ? std::count(nums.begin(), nums.end(), second.Number) : 0;

            std::vector<int> result;
            if (first_count > nums.size() / 3)
                result.push_back(first.Number);
            if (second_count > nums.size() / 3)
                result.push_back(second.Number);

            return result;
        }
    };
}
