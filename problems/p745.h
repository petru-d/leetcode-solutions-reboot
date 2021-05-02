#pragma once
#include <string>
#include <vector>

namespace p745
{
    class WordFilter
    {
      public:
        WordFilter(std::vector<std::string>& words)
        {
            auto W = words.size();
            for (size_t i = 0; i < W; ++i)
            {
                dict[words[i]] = i;
                std::reverse(words[i].begin(), words[i].end());
                rev_dict[words[i]] = i;
            }
        }

        int f(std::string prefix, std::string suffix)
        {
            auto [low, high] = get_range(dict, prefix);
            if (low == high)
                return -1;

            std::reverse(suffix.begin(), suffix.end());
            auto [rev_low, rev_high] = get_range(rev_dict, suffix);
            if (low == high)
                return -1;

            std::vector<size_t> preffix_fits;
            for (auto it = low; it != high; ++it)
                preffix_fits.push_back(it->second);

            std::vector<size_t> suffix_fits;
            for (auto it = rev_low; it != rev_high; ++it)
                suffix_fits.push_back(it->second);

            std::sort(preffix_fits.rbegin(), preffix_fits.rend());
            std::sort(suffix_fits.rbegin(), suffix_fits.rend());

            auto P = preffix_fits.size();
            auto R = suffix_fits.size();
            auto pos_p = 0;
            auto pos_r = 0;
            while (pos_p < P && pos_r < R)
            {
                if (preffix_fits[pos_p] == suffix_fits[pos_r])
                    return preffix_fits[pos_p];

                if (preffix_fits[pos_p] > suffix_fits[pos_r])
                    ++pos_p;
                else
                    ++pos_r;
            }

            return -1;
        }

      private:
        using itm = std::map<std::string, size_t>::const_iterator;

        std::pair<itm, itm> get_range(const std::map<std::string, size_t>& d, const std::string& fix)
        {
            auto starts_with = [](const std::string& s, const std::string& preffix) { return s.rfind(preffix, 0) == 0; };

            auto low = d.lower_bound(fix);
            if (low == d.end())
                return {d.end(), d.end()};

            if (!starts_with(low->first, fix))
                low = std::next(low);
            if (low == d.end())
                return {d.end(), d.end()};

            auto high = low;
            while (true)
            {
                ++high;
                if (high == d.end())
                    break;
                if (!starts_with(high->first, fix))
                    break;
            }
            return {low, high};
        };

        std::map<std::string, size_t> dict;
        std::map<std::string, size_t> rev_dict;
    };
    class WordFilter2
    {
      public:
        WordFilter2(std::vector<std::string>& words)
        {
            auto W = words.size();
            for (size_t i = 0; i < W; ++i)
            {
                dict[words[i]] = i;
            }
        }

        int f(std::string prefix, std::string suffix)
        {
            auto [low, high] = get_range(dict, prefix);
            if (low == high)
                return -1;

            std::reverse(suffix.begin(), suffix.end());

            std::map<std::string, size_t> rev_dict;
            for (auto it = low; it != high; ++it)
            {
                auto word = it->first;

                std::reverse(word.begin(), word.end());
                rev_dict[word] = it->second;
            }

            auto [rev_low, rev_high] = get_range(rev_dict, suffix);
            if (rev_low == rev_high)
                return -1;

            auto best = rev_low->second;
            for (auto it = std::next(rev_low); it != rev_high; ++it)
                best = std::max(best, it->second);

            return int(best);
        }

      private:
        using itm = std::map<std::string, size_t>::const_iterator;

        std::pair<itm, itm> get_range(const std::map<std::string, size_t>& d, const std::string& fix)
        {
            auto starts_with = [](const std::string& s, const std::string& preffix) { return s.rfind(preffix, 0) == 0; };

            auto low = d.lower_bound(fix);
            if (low == d.end())
                return {d.end(), d.end()};

            if (!starts_with(low->first, fix))
                low = std::next(low);
            if (low == d.end())
                return {d.end(), d.end()};

            auto starts_with_fix2 = [&](const auto& s) { return s.first.rfind(fix, 0) == 0; };

            auto high = std::partition_point(low, d.end(), starts_with_fix2);

            return {low, high};
        };

        std::map<std::string, size_t> dict;
        std::map<std::string, size_t> rev_dict;
    };
    class WordFilter3
    {
      public:
        WordFilter3(std::vector<std::string>& words)
        {
            auto WW = words.size();
            for (size_t i = WW; i > 0; --i)
            {
                auto* curr_pref = _pref;
                auto* curr_suff = _suff;

                auto W = words[i - 1].size();
                for (size_t l = 0; l < W; ++l)
                {
                    auto pref_letter = words[i - 1][l];

                    if (curr_pref->Children[pref_letter - 'a'] == nullptr)
                        curr_pref->Children[pref_letter - 'a'] = new TrieNode();
                    curr_pref = curr_pref->Children[pref_letter - 'a'];
                    curr_pref->Indices.push_back(i - 1);

                    auto suff_letter = words[i - 1][W - 1 - l];

                    if (curr_suff->Children[suff_letter - 'a'] == nullptr)
                        curr_suff->Children[suff_letter - 'a'] = new TrieNode();
                    curr_suff = curr_suff->Children[suff_letter - 'a'];
                    curr_suff->Indices.push_back(i - 1);
                }
            }
        }

        int f(std::string prefix, std::string suffix)
        {
            auto* curr_pref = _pref;
            for (auto p : prefix)
            {
                curr_pref = curr_pref->Children[p - 'a'];
                if (!curr_pref)
                    return -1;
            }

            auto* curr_suff = _suff;
            for (auto it = suffix.rbegin(); it != suffix.rend(); ++it)
            {
                curr_suff = curr_suff->Children[*it - 'a'];
                if (!curr_suff)
                    return -1;
            }

            const auto& pref_fit = curr_pref->Indices;
            const auto& suff_fit = curr_suff->Indices;
            auto P = pref_fit.size();
            auto R = suff_fit.size();
            auto pos_p = 0;
            auto pos_r = 0;

            while (pos_p < P && pos_r < R)
            {
                if (pref_fit[pos_p] == suff_fit[pos_r])
                    return pref_fit[pos_p];

                if (pref_fit[pos_p] > suff_fit[pos_r])
                    ++pos_p;
                else
                    ++pos_r;
            }

            return -1;
        }

        struct TrieNode
        {
            std::vector<size_t> Indices;
            std::array<TrieNode*, 26> Children = {};
        };
        TrieNode* _pref = new TrieNode();
        TrieNode* _suff = new TrieNode();
    };
}
