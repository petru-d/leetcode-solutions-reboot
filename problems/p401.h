#pragma once
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <cmath>

namespace p401
{
    class Solution
    {
      public:
        std::vector<std::string> readBinaryWatch(int num)
        {
            if (num == 0)
                return {"0:00"};
            if (num > 8)
                return {};

            std::vector<std::string> result;

            for (size_t h = 0; h <= std::min(num, 3); ++h)
            {
                size_t m = num - h;
                if (m >= 6)
                    continue;

                auto combos = make_combos(h, m);

                std::copy(combos.begin(), combos.end(), std::back_inserter(result));
            }

            return result;
        }

      private:
        std::vector<std::string> make_combos(size_t h, size_t m)
        {
            std::set<size_t> h_combos = make_combo(h, 4, 11);
            std::set<size_t> m_combos = make_combo(m, 6, 59);

            auto make_mins = [](size_t m) { return ((m < 10) ? "0" : "") + std::to_string(m); };

            std::vector<std::string> combos;
            for (const auto& hc : h_combos)
                for (const auto& mc : m_combos)
                    combos.push_back(std::to_string(hc) + ":" + make_mins(mc));
            return combos;
        }

        std::set<size_t> make_combo(size_t bits_set, size_t max_bits, size_t max_val)
        {
            if (bits_set == 0)
                return {0};
            if (bits_set == max_bits)
            {
                auto all_bits = static_cast<size_t>(pow(2, max_bits) - 1);

                std::set<size_t> result;
                if (all_bits <= max_val)
                    result.insert(all_bits);
                return result;
            }

            std::set<size_t> result;
            {
                auto from_less_bits = make_combo(bits_set, max_bits - 1, max_val);

                std::set<size_t> from_less_bits2;
                std::transform(from_less_bits.begin(), from_less_bits.end(),
                               std::inserter(from_less_bits2, from_less_bits2.end()), [](size_t x) { return 2 * x; });

                result.merge(from_less_bits);
                result.merge(from_less_bits2);
            }
            {
                auto less_bits = make_combo(bits_set - 1, max_bits - 1, max_val);

                std::set<size_t> less_bits_add_at_end;
                std::transform(less_bits.begin(), less_bits.end(),
                               std::inserter(less_bits_add_at_end, less_bits_add_at_end.end()),
                               [](size_t x) { return 2 * x + 1; });

                std::set<size_t> less_bits_add_front;
                std::transform(less_bits.begin(), less_bits.end(), std::inserter(less_bits_add_front, less_bits_add_front.end()),
                               [max_bits](size_t x) { return x + static_cast<size_t>(pow(2, max_bits - 1)); });

                result.merge(less_bits_add_front);
                result.merge(less_bits_add_at_end);
            }

            std::set<size_t> result_clipped;
            for (auto r : result)
                if (r <= max_val)
                    result_clipped.insert(r);
            return result_clipped;
        }
    };
}