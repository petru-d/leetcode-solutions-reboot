#pragma once
#include <array>
#include <string>
#include <vector>

namespace p1275
{
    class Solution
    {
      public:
        std::string tictactoe(std::vector<std::vector<int>>& moves)
        {
            std::array<std::array<int, 3>, 3> table = {};

            int player = 0;
            for (const auto& m : moves)
            {
                table[m[0]][m[1]] = player + 1;
                player = (player + 1) % 2;
            }

            auto test_3 = [](int v1, int v2, int v3) -> std::optional<std::string> {
                if (v1 != v2 || v2 != v3 || v1 == 0)
                    return std::optional<std::string>{};

                return v1 == 1 ? "A" : "B";
            };

            auto test_line = [&](size_t l) { return test_3(table[l][0], table[l][1], table[l][2]); };
            auto test_column = [&](size_t c) { return test_3(table[0][c], table[1][c], table[2][c]); };
            auto test_d1 = [&]() { return test_3(table[0][0], table[1][1], table[2][2]); };
            auto test_d2 = [&]() { return test_3(table[0][2], table[1][1], table[2][0]); };

            for (size_t i = 0; i < 3; ++i)
            {
                if (auto w = test_line(i))
                    return w.value();
                if (auto w = test_column(i))
                    return w.value();
            }
            if (auto w = test_d1())
                return w.value();
            if (auto w = test_d2())
                return w.value();

            return moves.size() == 9 ? "Draw" : "Pending";
        }
    };
}
