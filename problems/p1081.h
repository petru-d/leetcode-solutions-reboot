#pragma once

#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>

namespace p1081
{
    class Solution
    {
      public:
        // The idea (from leetcode): keep a stack containing the current answer. At each step, if the letter is not in the answer,
        // add it, otherwise ignore it.
        // The trick: when adding a letter to the answer, look at the current answer's tail: if it is bigger than the current
        // letter, see if it is possible to select the tail later. If yes, discard the tail. Repeat as much as possible.
        //
        // This operation ensures that at each step the current answer is the best possible that is also still viable (we don't
        // discard if there are no more available later).
        std::string smallestSubsequence(std::string text)
        {
            std::unordered_map<char, size_t> still_available;

            for (auto i : text)
                still_available[i]++;

            std::string ans = "";
            std::bitset<26> in_answer;

            for (auto ch : text)
            {
                // if the current answer already contains the letter, just ignore it - we don't want two of them
                if (in_answer[size_t(ch) - 'a'])
                {
                    still_available[ch]--;
                    continue;
                }

                // The current letter is not part of the answer - it will need to be added

                // As long as the current letter is smaller than the last of the answer and we can select the last of the answer
                // later on, remove the last in the answer.
                while (ans.size() > 0 && ch < ans.back() && still_available[ans.back()] > 0)
                {
                    in_answer[size_t(ans.back()) - 'a'] = 0;
                    ans.pop_back();
                }

                // Add the letter to the answer and mark that it is now in use
                ans.push_back(ch);
                in_answer[size_t(ch) - 'a'] = true;
                still_available[ch]--;
            }

            return ans;
        }
    };
}