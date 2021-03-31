#pragma once
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

namespace p936
{
    class Solution
    {
      public:
        std::vector<int> movesToStamp(std::string stamp, std::string target)
        {
            auto T = target.size();
            auto S = stamp.size();
            std::vector<int> result;

            std::unordered_set<size_t> remaining;
            for (size_t i = 0; i < T; ++i)
                remaining.insert(i);

            auto unstamp = [&](size_t pos) {
                for (size_t i = 0; i < S; ++i)
                {
                    target[i + pos] = '?';
                    auto it = remaining.find(i + pos);
                    if (it != remaining.end())
                        remaining.erase(it);
                }
            };

            size_t pos_last_stamp = 0;
            while (true)
            {
                pos_last_stamp = target.find(stamp, pos_last_stamp);
                if (pos_last_stamp == -1)
                    break;

                result.push_back(pos_last_stamp);
                unstamp(pos_last_stamp);
                pos_last_stamp += S;
            }
            // could not apply the first unstamping - meaning that the stamp is not present in the target
            // this means it is impossible to stamp
            if (result.empty())
                return result;

            // checks if "stamp_count" characters from the right side of stamp
            // can be unstamped in target at positions starting with "target_pos"
            auto match_right = [&](size_t stamp_count, size_t target_pos) {
                if (target_pos + stamp_count - 1 >= T)
                    return false;

                for (auto i = 0; i < stamp_count; ++i)
                    if (target[target_pos + i] != stamp[S - stamp_count + i] && target[target_pos + i] != '?')
                        return false;

                return true;
            };

            // checks if "stamp_count" characters from the left side of stamp
            // can be unstamped in target at positions starting with "target_pos"
            auto match_left = [&](size_t stamp_count, size_t target_pos) {
                if (target_pos < stamp_count - 1)
                    return false;

                for (size_t i = 0; i < stamp_count; ++i)
                    if (target[target_pos + i - stamp_count + 1] != stamp[i] && target[target_pos + i - stamp_count + 1] != '?')
                        return false;
                return true;
            };

            while (!remaining.empty())
            {
                bool match_found = false;
                for (auto r : remaining)
                {
                    // see if we find a right edge
                    if (r > 0 && target[r - 1] == '?')
                    {
                        for (size_t j = 1; j <= S; ++j)
                            if (match_right(j, r))
                            {
                                // ???????TTTTTT
                                //     SSSSS
                                result.push_back(r - S + j);
                                unstamp(r - S + j);
                                match_found = true;
                                break;
                            }
                        if (match_found)
                            break;
                    }
                    // see if we find a left edge
                    else if (r < T - 1 && target[r + 1] == '?')
                    {
                        for (size_t j = 1; j <= S; ++j)
                            if (match_left(j, r))
                            {
                                // TTTTTT??????
                                //     SSSSS
                                result.push_back(r - j + 1);
                                unstamp(r - j + 1);
                                match_found = true;
                                break;
                            }
                        if (match_found)
                            break;
                    }
                }

                // could not consume anything
                if (!match_found)
                    return {};
            }

            std::reverse(result.begin(), result.end());
            return result;
        }
    };
}
