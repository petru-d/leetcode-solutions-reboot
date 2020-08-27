#pragma once
#include <string>
#include <vector>

namespace p412
{
    class Solution
    {
      public:
        std::vector<std::string> fizzBuzz(int n)
        {
            std::vector<std::string> result;
            result.reserve(size_t(n));
            for (int i = 1; i <= n; ++i)
            {
                bool p3 = (i % 3 == 0);
                bool p5 = (i % 5 == 0);

                std::string r;
                if (p3)
                    r = "Fizz";
                if (p5)
                    r += "Buzz";
                if (r.empty())
                    r = std::to_string(i);

                result.push_back(std::move(r));
            }

            return result;
        }
    };
}
