#pragma once
#include <vector>

namespace p348
{
    class TicTacToe
    {
      public:
        TicTacToe(int n)
        {
            N = size_t(n);
            cols = rows = std::vector<StateVal>(N, StateVal{});
        }

        int move(int row, int col, int player)
        {
            State playerAsState = player == 1 ? State::OnlyP1 : State::OnlyP2;

            auto updateState = [&](StateVal& sv, State playerState) {
                if (sv.state != State::Both)
                {
                    if (sv.state == State::None)
                        sv.state = playerState;
                    else if (sv.state != playerState)
                        sv.state = State::Both;
                }

                ++sv.val;

                if (sv.val == N && sv.state == State::OnlyP1)
                    return 1;
                if (sv.val == N && sv.state == State::OnlyP2)
                    return 2;
                return 0;
            };

            if (auto resRow = updateState(rows[row], playerAsState); resRow != 0)
                return resRow;

            if (auto resCol = updateState(cols[col], playerAsState); resCol != 0)
                return resCol;

            if (row == col)
            {
                if (auto resD1 = updateState(d1, playerAsState); resD1 != 0)
                    return resD1;
            }

            if (row + col == int(N) - 1)
            {
                if (auto resD2 = updateState(d2, playerAsState); resD2 != 0)
                    return resD2;
            }

            return 0;
        }

        enum class State
        {
            None,
            OnlyP1,
            OnlyP2,
            Both
        };
        struct StateVal
        {
            State state = State::None;
            size_t val = 0;
        };

        size_t N = -1;
        std::vector<StateVal> rows;
        std::vector<StateVal> cols;
        StateVal d1;
        StateVal d2;
    };
}
