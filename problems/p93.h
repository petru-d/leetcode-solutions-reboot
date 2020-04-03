#pragma once
#include <cassert>
#include <string>
#include <vector>

using namespace std;

namespace p93
{
    class Solution
    {
      public:
        vector<string> restoreIpAddresses(string s)
        {
            if (s.size() < 4 || s.size() > 12)
                return {};

            // generate {p1, p2, p3} such that
            //  0 < p1 < p2 < p3 < s.size()
            //  0 <= s[0 .. p1) < 256   (but only allow '0' by itself, no '01' '001' etc)
            //  0 <= s[p1 .. p2) < 256
            //  0 <= s[p2 .. p3) < 256
            //  0 <= s[p3 .. s.size()) < 256
            vector<size_t> currSol = {1};
            backtrack(s, currSol);

            return _solutions;
        }

      private:
        void backtrack(const string& s, vector<size_t>& currSol)
        {
            if (currSol.size() == 3 || !viable(s, currSol))
            {
                if (solution(s, currSol))
                {
                    log_solution(s, currSol);
                }

                auto last = currSol.back();
                if (last < s.size() - 1)
                {
                    ++currSol[currSol.size() - 1];
                    return backtrack(s, currSol);
                }
                else
                {
                    currSol.pop_back();
                    if (currSol.empty())
                        return;
                    ++currSol[currSol.size() - 1];
                    return backtrack(s, currSol);
                }
            }
            else
            {
                currSol.push_back(1 + currSol.back());
                return backtrack(s, currSol);
            }
        }

        bool viable(const string& s, const vector<size_t>& currSol)
        {
            if (currSol.size() == 1)
            {
                // we need enough chars for the remaining blocks
                size_t remaining_chars = s.size() - currSol[0];
                if (remaining_chars < 3 || remaining_chars > 9)
                    return false;

                return good_block(s, 0, currSol[0]);
            }
            if (currSol.size() == 2)
            {
                // we need enough chars for the remaining blocks
                size_t remaining_chars = s.size() - currSol[1];
                if (remaining_chars < 2 || remaining_chars > 6)
                    return false;

                return good_block(s, currSol[0], currSol[1]);
            }

            assert(false);
            return false;
        }

        bool solution(const string& s, const vector<size_t>& currSol)
        {
            if (currSol.size() == 3)
            {
                // test the lenghts of the last 2 blocks (the others were checked by "viable")
                // only test that their sizes are smaller or equal to 3. they are greater or equal to 1 by construction
                auto part3_len = currSol[2] - currSol[1];
                auto part4_len = s.size() - currSol[2];
                if (part3_len > 3 || part4_len > 3)
                    return false;

                return (good_block(s, currSol[1], currSol[2]) && good_block(s, currSol[2], s.size()));
            }

            return false;
        }

        bool good_block(const string& s, size_t l, size_t r)
        {
            // The only allowed block that starts with '0' is '0'. No '01', '001' etc.
            if (s[l] == '0')
                return l + 1 == r;

            int result = 0;
            for (size_t i = l; i < r; ++i)
            {
                result *= 10;
                result += (s[i] - '0');
            }
            return result < 256;
        }

        void log_solution(const string& s, const vector<size_t>& solution)
        {
            auto sol = s.substr(0, solution[0]) + ".";
            sol += s.substr(solution[0], solution[1] - solution[0]) + ".";
            sol += s.substr(solution[1], solution[2] - solution[1]) + ".";
            sol += s.substr(solution[2]);

            _solutions.emplace_back(sol);
        }

        vector<string> _solutions;
    };
}
