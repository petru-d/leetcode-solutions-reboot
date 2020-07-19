#pragma once
#include <algorithm>
#include <string>

namespace p67
{
    class Solution
    {
      public:
        std::string addBinary(std::string a, std::string b)
        {
            auto A = a.size();
            auto B = b.size();
            auto M = std::max(a.size(), b.size());

            std::string result;
            result.reserve(M);

            bool carry = false;
            for (size_t i = 0; i < M; ++i)
            {
                bool aval = (i + 1 <= A) ? (a[A - i - 1] - '0') : false;
                bool bval = (i + 1 <= B) ? (b[B - i - 1] - '0') : false;

                result.push_back('0' + int(aval ^ bval ^ carry));

                carry = (aval && bval) || (aval && carry) || (bval && carry);
            }
            if (carry)
                result.push_back('1');

            std::reverse(result.begin(), result.end());
            return result;
        }
    };

}
