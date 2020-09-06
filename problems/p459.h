#pragma once
#include <string>
#include <vector>

namespace p459
{
    class Solution
    {
      public:
        bool repeatedSubstringPattern(std::string s)
        {
            size_t N = s.size();
            if (N <= 1)
                return false;

            std::vector<size_t> checks;
            for (size_t i = 1; i <= N / 2; ++i)
            {
                if (N % i == 0)
                    checks.push_back(i);
            }

            while (!checks.empty())
            {
                auto check = checks.back();
                if (do_check(s, check))
                    return true;

                std::vector<size_t> newChecks;
                for (const auto c : checks)
                {
                    if (check % c != 0)
                        newChecks.push_back(c);
                }

                checks = std::move(newChecks);
            }

            return false;
        }

      private:
        bool do_check(const std::string& data, size_t check)
        {
            size_t N = data.size();

            size_t steps = N / check;

            for (size_t c = 0; c < check; ++c)
                for (size_t s = 1; s < steps; ++s)
                    if (data[c] != data[c + s * check])
                        return false;

            return true;
        }
    };
}
