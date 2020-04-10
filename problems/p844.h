#pragma once
#include <string>

namespace p844
{
    class Solution
    {
      public:
        bool backspaceCompare(std::string S, std::string T)
        {
            // applies backspaces "in place" - just replaces letters with #
            apply_backspaces(S);
            apply_backspaces(T);

            return equal_ignore_hash(S, T);
        }

      private:
        void apply_backspaces(std::string& S)
        {
            int last_no_hash = -1;
            size_t SS = S.size();
            for (size_t i = 0; i < SS; ++i)
            {
                if (S[i] == '#' && last_no_hash >= 0)
                {
                    // gotcha here: it is possible that the last_no_hash is actually a hash - this happens when 2 or more
                    // backspaces come after a normal letter
                    while (last_no_hash >= 0 && S[static_cast<int>(last_no_hash)] == '#')
                        --last_no_hash;
                    if (last_no_hash >= 0)
                    {
                        S[static_cast<int>(last_no_hash)] = '#';
                        --last_no_hash;
                    }
                    continue;
                }

                last_no_hash = static_cast<int>(i);
            }
        }

        bool equal_ignore_hash(const std::string& S, const std::string& T)
        {
            size_t currT = 0;
            size_t SS = S.size();
            size_t ST = T.size();
            for (size_t s = 0; s < SS; ++s)
            {
                if (S[s] == '#')
                    continue;
                // S[s] needs a correspondant in T
                while (currT < ST && T[currT] != S[s])
                    ++currT;

                // not found
                if (currT == ST)
                    return false;

                // found, but consumed
                ++currT;
            }

            // all non # characters in S were matched
            return true;
        }
    };
}