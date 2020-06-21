#pragma once

#include <array>
#include <set>
#include <string>
#include <unordered_map>

namespace p1044
{
    class Solution
    {
      public:
        std::string longestDupSubstring(std::string S)
        {
            search(S);

            return best;
        }

      private:
        void search(const std::string& s)
        {
            auto have_repeating = [this, &s](int len) {
                if (len <= 0)
                    return true;
                if (len >= int(s.size()))
                    return false;

                using signature = long long int;
                std::unordered_map<signature, std::vector<int>> signatures;

                long long int p = 19260817;

                long long int ak = 1;
                for (int i = 0; i < len - 1; i++)
                    ak = (ak * 26) % p;

                auto make_first_signature = [p, &s, len]() {
                    signature res = 0;
                    for (int i = 0; i < len; i++)
                        res = (26 * res + (long long int)(s[i] - 'a')) % p;
                    return res;
                };

                auto roll_signature = [ak, p](signature& sig, char out, char in) {
                    sig = (26 * (sig - (long long int)(out - 'a') * ak) + (long long int)(in - 'a')) % p;
                    if (sig < 0)
                        sig += p;
                };

                auto same_substr = [](const std::string& s, int len, int i1, int i2) {
                    for (int i = 0; i < len; ++i)
                        if (s[size_t(i1) + i] != s[size_t(i2) + i])
                            return false;
                    return true;
                };

                auto curr_sig = make_first_signature();
                signatures[curr_sig] = {0};

                for (int i = 1; i <= int(s.size()) - len; ++i)
                {
                    // make the signature for the array starting at i with length len
                    roll_signature(curr_sig, s[size_t(i) - 1], s[size_t(i) + len - 1]);

                    // if this signature is not present in the map, add it and continue
                    auto pos_curr_sig = signatures.find(curr_sig);
                    if (pos_curr_sig == signatures.end())
                    {
                        signatures[curr_sig] = {i};
                        continue;
                    }

                    // the signature was found - check to see if it is a collision or a proper equality
                    auto& indices_with_same_signature = pos_curr_sig->second;
                    for (auto is : indices_with_same_signature)
                    {
                        if (same_substr(s, len, i, is))
                        {
                            // equality - store solution
                            best = s.substr(i, len);
                            return true;
                        }
                    }

                    // collision
                    indices_with_same_signature.push_back(i);
                }

                return false;
            };

            int S = int(s.size());
            int x = -1;
            for (int k = S; k >= 1; k /= 2)
            {
                while (have_repeating(x + k))
                    x += k;
            }
        }

        // x + 1 is the len for which we don't have repeating

        std::string best;
    };
}
