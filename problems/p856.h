#pragma once
#include <numeric>
#include <stack>
#include <string>
#include <vector>

namespace p856
{
    class Solution
    {
      public:
        int scoreOfParentheses(std::string S)
        {
            std::stack<std::vector<int>> score;
            score.push(std::vector<int>{-1});
            for (size_t i = 1; i < S.size(); ++i)
            {
                if (S[i] == '(')
                {
                    auto& t = score.top();
                    if (t.back() == -1)
                    {
                        score.push(std::vector<int>{-1});
                    }
                    else
                    {
                        t.push_back(-1);
                    }
                }
                else
                {
                    auto& t = score.top();
                    if (t.back() == -1)
                    {
                        t.back() = 1;
                    }
                    else
                    {
                        auto level_score = std::accumulate(t.begin(), t.end(), 0);
                        score.pop();
                        score.top().back() = 2 * level_score;
                    }
                }
            }

            auto final_score = std::accumulate(score.top().begin(), score.top().end(), 0);

            return final_score;
        }
    };
}
