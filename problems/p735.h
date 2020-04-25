#pragma once
#include <vector>

namespace p735
{
    class Solution
    {
      public:
        std::vector<int> asteroidCollision(std::vector<int>& asteroids)
        {
            size_t A = asteroids.size();

            std::vector<int> result;
            result.reserve(A);

            // ensure we start positive
            size_t i = 0;
            while (i < A && asteroids[i] < 0)
            {
                result.push_back(asteroids[i]);
                ++i;
            }
            if (i == A)
                return result;

            result.push_back(asteroids[i]);

            for (size_t j = i + 1; j < A; ++j)
            {
                if (asteroids[j] >= 0)
                    result.push_back(asteroids[j]);
                else
                {
                    // current is negative
                    if (result.empty() || result.back() < 0)
                        result.push_back(asteroids[j]);
                    else
                    {
                        // current is negative and last in result is positive
                        if (abs(asteroids[j]) < result.back())
                            continue;
                        else if (abs(asteroids[j]) == result.back())
                            result.pop_back();
                        else
                        {
                            // current is negative and last in result is positive (but not big enough)
                            // this means that the current starts sweeping in result
                            while (!result.empty() && abs(asteroids[j]) > result.back() && result.back() >= 0)
                                result.pop_back();

                            if (result.empty() || result.back() < 0)
                                result.push_back(asteroids[j]);
                            else
                            {
                                // last in result is positive - if equal in magnitute, pop
                                if (abs(asteroids[j]) == result.back())
                                    result.pop_back();
                            }
                        }
                    }
                }
            }

            return result;
        }
    };
}