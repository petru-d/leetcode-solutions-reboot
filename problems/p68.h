#pragma once

#include <numeric>
#include <string>
#include <vector>

using namespace std;
namespace p68
{
    class Solution
    {
      public:
        vector<string> fullJustify(vector<string>& words, int maxWidth)
        {
            // gather the indices of words that will fit in each row.
            vector<vector<size_t>> split_words = {{0}};

            // size filled in the current row
            size_t last_row_filled = words[0].size();

            for (size_t w = 1; w < words.size(); ++w)
            {
                // If we can't fit "w" in the last string in the result, make a new line that starts with "w".
                if (last_row_filled + words[w].size() + 1 <= maxWidth)
                {
                    split_words.back().push_back(w);
                    last_row_filled += words[w].size() + 1;
                }
                else
                {
                    split_words.push_back({w});
                    last_row_filled = words[w].size();
                }
            }

            vector<string> result;

            // Split_words should now contain references to the words that should fit on each row.
            // Justify.
            for (size_t row = 0; row < split_words.size() - 1; ++row)
            {
                result.push_back(justify_center(words, split_words[row], maxWidth));
            }
            result.push_back(justify_left(words, split_words.back(), maxWidth));

            return result;
        }

      private:
        string justify_center(const vector<string>& words, const vector<size_t>& word_indices, int maxWidth)
        {
            if (word_indices.size() <= 1)
                return justify_left(words, word_indices, maxWidth);

            // how many space characters we need
            size_t spaces = static_cast<size_t>(maxWidth);
            for (const auto& wi : word_indices)
                spaces -= words[wi].size();

            // how many gaps there are
            size_t total_gaps = word_indices.size() - 1;

            size_t small_gap_size = spaces / total_gaps;
            size_t big_gap_size = small_gap_size + 1;

            // distribute the left-overs to the big gaps, one each
            size_t number_of_big_gaps = spaces % total_gaps;
            // size_t number_of_small_gaps = total_gaps - number_of_big_gaps;

            string result = words[word_indices[0]];

            for (size_t i = 1; i < word_indices.size(); ++i)
            {
                bool use_big_gap = i - 1 < number_of_big_gaps;

                result += std::string(use_big_gap ? big_gap_size : small_gap_size, ' ') + words[word_indices[i]];
            }

            return result;
        }

        string justify_left(const vector<string>& words, const vector<size_t>& word_indices, int maxWidth)
        {
            string result = words[word_indices[0]];
            for (size_t w = 1; w < word_indices.size(); ++w)
            {
                result += " " + words[word_indices[w]];
            }

            // pad if needed
            if (result.size() < maxWidth)
            {
                result += std::string(maxWidth - result.size(), ' ');
            }
            return result;
        }
    };
}