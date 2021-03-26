#pragma once
#include <algorithm>
#include <array>
#include <string>
#include <vector>

namespace p916
{
    class Solution
    {
      public:
        std::vector<std::string> wordSubsets(std::vector<std::string>& A, std::vector<std::string>& B)
        {
            using Signature = std::array<size_t, 26>;

            auto extract_signature = [](const std::string& b) {
                Signature sign = {};
                for (auto l : b)
                {
                    ++sign[l - 'a'];
                }
                return sign;
            };

            auto update_cover = [](Signature& cover, const Signature& sign) {
                for (size_t i = 0; i < cover.size(); ++i)
                    cover[i] = std::max(cover[i], sign[i]);
            };

            // Does a cover b ?
            auto covers = [](const Signature& a, const Signature& b) {
                for (size_t i = 0; i < a.size(); ++i)
                    if (a[i] < b[i])
                        return false;
                return true;
            };

            Signature bCover = {};
            for (const auto& b : B)
            {
                auto bSign = extract_signature(b);
                update_cover(bCover, bSign);
            }

            std::vector<std::string> result;
            for (auto& a : A)
            {
                if (covers(extract_signature(a), bCover))
                    result.push_back(std::move(a));
            }
            return result;
        }
    };
}
