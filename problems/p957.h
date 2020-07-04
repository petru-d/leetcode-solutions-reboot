#pragma once

#include <bitset>
#include <vector>

namespace p957
{
    class Solution
    {
      public:
        std::vector<int> prisonAfterNDays(std::vector<int>& cells, int N)
        {
            if (N == 0)
                return std::move(cells);

            std::bitset<8> bits = get(cells);

            std::vector<uint8_t> saw{get_num(bits)};
            saw.reserve(64);

            size_t cycle_start = -1;
            size_t cycle_size = -1;

            while (true)
            {
                bits = advance(bits);

                auto bits_n = get_num(bits);

                auto pos = std::find(saw.begin(), saw.end(), bits_n);
                if (pos != saw.end())
                {
                    cycle_start = std::distance(saw.begin(), pos);
                    cycle_size = std::distance(pos, saw.end());
                    break;
                }
                saw.push_back(bits_n);
            }

            if (N < cycle_start + cycle_size)
                return make(saw[N]);

            return make(saw[cycle_start + (N - cycle_start) % cycle_size]);
        }

      private:
        std::vector<int> make(uint8_t n)
        {
            std::vector<int> result;
            for (int i = 1; i <= 8; ++i)
            {
                result.push_back(n & 1);
                n = n >> 1;
            }

            return result;
        }

        std::bitset<8> get(const std::vector<int>& cells)
        {
            std::bitset<8> res = {};
            for (size_t i = 0; i < 8; ++i)
                res[i] = (cells[i] == 1);

            return res;
        }

        uint8_t get_num(const std::bitset<8>& bits)
        {
            return static_cast<uint8_t>(bits.to_ulong());
        }

        std::bitset<8> advance(const std::bitset<8>& bits)
        {
            std::bitset<8> new_bits{};

            for (size_t i = 1; i <= 6; ++i)
            {
                new_bits[i] = !(bits[i - 1] ^ bits[i + 1]);
            }

            return new_bits;
        }
    };
}
