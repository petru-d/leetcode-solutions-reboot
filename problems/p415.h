#pragma once
#include <string>
#include <vector>

namespace p415
{
    class Solution
    {
      public:
        std::string addStrings(std::string num1, std::string num2)
        {
            auto to_rev_vec = [](const std::string& num) {
                std::vector<int> res;
                res.reserve(num.size());
                for (auto i = num.rbegin(); i != num.rend(); ++i)
                    res.push_back(*i - '0');
                return res;
            };

            std::vector<int> n1rev = to_rev_vec(num1);
            std::vector<int> n2rev = to_rev_vec(num2);
            auto N1 = n1rev.size();
            auto N2 = n2rev.size();

            if (N1 > N2)
            {
                std::swap(n1rev, n2rev);
                std::swap(N1, N2);
            }

            std::vector<int> res;
            res.reserve(N2);
            int carry = 0;
            for (size_t i = 0; i < N2; ++i)
            {
                auto [q, r] = std::div((i < N1 ? n1rev[i] : 0) + n2rev[i] + carry, 10);
                res.push_back(r);
                carry = q;
            }
            if (carry == 1)
                res.push_back(1);

            std::string resstr;
            resstr.reserve(res.size());
            for (auto i = res.rbegin(); i != res.rend(); ++i)
                resstr.push_back(*i + '0');
            return resstr;
        }
    };
}
