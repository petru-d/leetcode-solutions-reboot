#pragma once
#include <random>
#include <vector>

namespace p497
{
    class Solution
    {
      public:
        Solution(std::vector<std::vector<int>>& rects) : _rects(std::move(rects))
        {
            _pSum.reserve(_rects.size());
            _pSum.push_back(pointsCount(_rects[0]));
            auto R = _rects.size();
            for (size_t i = 1; i < R; ++i)
                _pSum.push_back(_pSum.back() + pointsCount(_rects[i]));

            std::random_device rd;
            _gen = std::mt19937(rd());
            _distrib = std::uniform_int_distribution<int>(1, _pSum.back());
        }

        std::vector<int> pick()
        {
            auto p = _distrib(_gen);

            // find the rectangle where p is located. we want the first element that is >= p.
            auto up = std::upper_bound(_pSum.begin(), _pSum.end(), p);
            if (up != _pSum.begin() && *(up - 1) == p)
                --up;

            size_t i = up - _pSum.begin();

            return toRectangle(_rects[i], p - (i != 0 ? _pSum[i - 1] : 0));
        }

      private:
        int pointsCount(const std::vector<int>& rect)
        {
            return (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
        }

        std::vector<int> toRectangle(const std::vector<int>& rect, int p)
        {
            int width = rect[2] - rect[0] + 1;
            // int height = rect[3] - rect[1];

            auto [line, col] = std::div(p - 1, width);

            return {rect[0] + col, rect[1] + line};
        }

        std::vector<std::vector<int>> _rects;
        std::vector<int> _pSum;

        std::mt19937 _gen;
        std::uniform_int_distribution<int> _distrib;
    };
}