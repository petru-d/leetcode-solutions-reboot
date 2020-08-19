#pragma once
#include <vector>

namespace p967
{
    class Solution
    {
      public:
        std::vector<int> numsSameConsecDiff(int N, int K)
        {
            if (N == 1)
            {
                return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            }

            if (K == 0)
            {
                std::vector<int> result;
                for (int i = 1; i <= 9; ++i)
                    result.push_back(make(std::vector<int>(size_t(N), i)));

                return result;
            }

            for (int i = 1; i <= 9; ++i)
            {
                std::vector<int> digits = {i};
                digits.reserve(size_t(N));
                go(N, K, digits);
            }
            return _solutions;
        }

      private:
        void go(int N, int K, std::vector<int>& digits)
        {
            if (digits.size() == size_t(N))
            {
                _solutions.push_back(make(digits));
                return;
            }

            std::vector<int> cont;
            int plus_K = digits.back() + K;
            if (0 <= plus_K && plus_K <= 9)
                cont.push_back(plus_K);
            int minus_K = digits.back() - K;
            if (0 <= minus_K && minus_K <= 9)
                cont.push_back(minus_K);

            for (const auto c : cont)
            {
                digits.push_back(c);
                go(N, K, digits);
                digits.pop_back();
            }
        }

        std::vector<int> _solutions;

        int make(const std::vector<int>& digits)
        {
            int result = 0;
            for (const auto d : digits)
                result = 10 * result + d;
            return result;
        }
    };
}
