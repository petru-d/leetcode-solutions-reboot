#pragma once
#include <string>
#include <vector>

namespace p647
{
    class Solution
    {
      public:
        // optimization(?) to the normal solution to expand around the center:
        // create an array that "condenses" a repetition of characters in the initial string into a single object
        // e.g. "aaaabbbccc" becomes {a, 4, 0, 3}, {b, 3, 4, 6}, {c, 3, 7, 9}
        // we do the expansion around the center in this array rather than the original string
        // Notes:
        // - this handles nicely the case from the standard implementation with even length palindromes.
        //   with this method, we always expand around the center
        // - if there are no repetition, this is worse (but not much more) than the standard implementation, as it requires an
        //   additional pass.
        int countSubstrings(std::string s)
        {
            if (s.empty())
                return 0;

            struct CharMul
            {
                char C = 0;
                size_t Multiplicity = -1;
                size_t Left = -1;
                size_t Right = -1;
            };

            std::vector<CharMul> v;
            v.reserve(s.size());
            v.push_back({s[0], 1, 0, 0});
            auto S = s.size();
            for (size_t i = 1; i < S; ++i)
            {
                if (s[i] != s[i - 1])
                    v.push_back({s[i], 1, i, i});
                else
                {
                    ++v.back().Multiplicity;
                    ++v.back().Right;
                }
            }

            int result = 0;
            auto V = v.size();
            for (size_t i = 0; i < V; ++i)
            {
                int span = 0;
                int j = 1;
                while (i >= j && i + j < V)
                {
                    if (v[i - j].C != v[i + j].C)
                        break;

                    span += std::min(v[i - j].Multiplicity, v[i + j].Multiplicity);

                    if (v[i - j].Multiplicity != v[i + j].Multiplicity)
                        break;
                    ++j;
                }

                result += span + v[i].Multiplicity * (v[i].Multiplicity + 1) / 2;
            }
            return result;
        }
    };
}
