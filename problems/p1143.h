#pragma once
#include <algorithm>
#include <string>
#include <vector>

namespace p1143
{
    class Solution
    {
      public:
        int longestCommonSubsequence_(std::string text1, std::string text2)
        {
            if (text1.empty() || text2.empty())
                return 0;

            size_t T1 = text1.size();
            size_t T2 = text2.size();

            std::vector<std::vector<uint16_t>> mat(T1, std::vector<uint16_t>(T2, 0));

            for (size_t i = 0; i < T1; ++i)
            {
                for (size_t j = 0; j < T2; ++j)
                {
                    uint16_t n_val = (i != 0) ? mat[i - 1][j] : 0;
                    uint16_t e_val = (j != 0) ? mat[i][j - 1] : 0;

                    uint16_t ne_val = (i != 0 && j != 0) ? mat[i - 1][j - 1] : 0;

                    mat[i][j] = std::max(n_val, e_val);
                    if (text1[i] == text2[j])
                        mat[i][j] = std::max(mat[i][j], uint16_t(ne_val + 1));
                }
            }
            return mat[T1 - 1][T2 - 1];
        }

        int longestCommonSubsequence(std::string text1, std::string text2)
        {
            if (text1.empty() || text2.empty())
                return 0;

            size_t T1 = text1.size();
            size_t T2 = text2.size();

            if (T2 > T1)
            {
                std::swap(T1, T2);
                std::swap(text1, text2);
            }

            std::vector<uint16_t> old_row(T2, 0);

            for (size_t i = 0; i < T1; ++i)
            {
                std::vector<uint16_t> new_row(T2, 0);

                for (size_t j = 0; j < T2; ++j)
                {
                    uint16_t n_val = (i != 0) ? old_row[j] : 0;
                    uint16_t e_val = (j != 0) ? new_row[j - 1] : 0;

                    uint16_t ne_val = (i != 0 && j != 0) ? old_row[j - 1] : 0;

                    new_row[j] = std::max(n_val, e_val);
                    if (text1[i] == text2[j])
                        new_row[j] = std::max(new_row[j], uint16_t(ne_val + 1));
                }
                old_row = std::move(new_row);
            }
            return old_row[T2 - 1];
        }
    };
}