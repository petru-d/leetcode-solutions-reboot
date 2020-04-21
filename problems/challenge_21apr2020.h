#pragma once

#include <vector>

namespace challenge_21apr2020
{

    // This is the BinaryMatrix's API interface.
    // You should not implement it, or speculate about its implementation
    class BinaryMatrix
    {
      public:
        explicit BinaryMatrix(const std::vector<std::vector<int>>& data) : _data(data)
        {
            if (data.empty())
                throw;
        }

        int get(int x, int y)
        {
            return _data[static_cast<int>(x)][static_cast<int>(y)];
        }

        std::vector<int> dimensions()
        {
            return {static_cast<int>(_data.size()), static_cast<int>(_data.front().size())};
        }

      private:
        std::vector<std::vector<int>> _data;
    };

    class Solution
    {
      public:
        int leftMostColumnWithOne(BinaryMatrix& binaryMatrix)
        {
            int best = -1;

            auto dims = binaryMatrix.dimensions();
            int L = dims[0];
            int C = dims[1];

            std::pair<int, int> point = {0, C - 1};

            int val = binaryMatrix.get(point.first, point.second);
            if (val == 1)
                best = point.second;

            enum class Direction
            {
                Down,
                Left
            };
            Direction direction = val == 0 ? Direction::Down : Direction::Left;

            while (true)
            {
                // go down as long as we are finding only zeros
                if (direction == Direction::Down)
                {
                    while (val == 0 && point.first < L - 1)
                    {
                        point = {point.first + 1, point.second};
                        val = binaryMatrix.get(point.first, point.second);
                        if (val == 1)
                            best = point.second;
                    }
                    if (val == 0)
                    {
                        // we reached the last row and we're on a zero - exit the main loop here.
                        break;
                    }
                    else
                    {
                        // we reached a one when descending - switch to moving left
                        direction = Direction::Left;
                    }
                }
                else // if (direction == Direction::Left)
                {
                    while (val == 1 && point.second > 0)
                    {
                        point = {point.first, point.second - 1};
                        val = binaryMatrix.get(point.first, point.second);
                        if (val == 1)
                            best = point.second;
                    }
                    if (val == 1)
                    {
                        // we reached the last column and we're still on a zero - could return zero, but i like to exit the main
                        // loop here, for symmetry
                        break;
                    }
                    else
                    {
                        direction = Direction::Down;
                    }
                }
            }

            return best;
        }
    };
}