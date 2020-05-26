#pragma once

#include <vector>

namespace p1103
{
    class Solution
    {
      public:
        std::vector<int> distributeCandies2(int candies, int num_people)
        {
            if (num_people <= 1)
                return {candies};

            std::vector<int> result(size_t(num_people), 0);

            int curr_candy = 0;
            int curr_index = 0;
            int remaining = candies;
            while (remaining > 0)
            {
                ++curr_candy;
                if (remaining < curr_candy)
                    curr_candy = remaining;

                result[curr_index] += curr_candy;
                remaining -= curr_candy;
                curr_index = (curr_index + 1) % num_people;
            }

            return result;
        }

        std::vector<int> distributeCandies(int candies, int num_people)
        {
            // closest triangular number to <candies> - this is how many times we will distribute "complete" candy portions.
            int k = int((-1 + sqrt(8 * size_t(candies) + 1)) / 2);

            // the size of the last "incomplete" portion (can be zero)
            int incomplete_portion_size = candies - k * (k + 1) / 2;

            // how many times we will go around completely
            // how many people in the last (incomplete) round will get a "complete" candy portion
            auto [full_cycles, last_cycle_full_portion] = div(k, num_people);

            std::vector<int> result(size_t(num_people), 0);
            for (size_t i = 0; i < size_t(num_people); ++i)
            {
                // number of "full portions" for this person:
                // - the number of complete cycles
                // - add one, if the person is at the start of the row, before the full portions finish
                int t = full_cycles + ((int(i) + 1) <= last_cycle_full_portion ? 1 : 0);

                // the candy for one person:
                // - (i + 1) + (n + i + 1) + (2n + i + 1) + ... in total k terms - rewritten as t(i + 1) + nt(t+1)/2
                // - add the incomplete portion, if this person gets it
                result[i] = t * (int(i) + 1) + num_people * t * (t - 1) / 2;
                if (i == last_cycle_full_portion)
                    result[i] += incomplete_portion_size;
            }
            return result;
        }
    };
}