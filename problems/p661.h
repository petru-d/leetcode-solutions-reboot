#pragma once
#include <vector>

namespace p661
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img)
        {
            int R = img.size();
            int C = img.front().size();

            auto in_range = [&](int x, int y) { return 0 <= x && x < R && 0 <= y && y < C; };

            std::vector<std::vector<int>> res(R, std::vector<int>(C, 0));

            for (auto x = 0; x < R; ++x)
                for (auto y = 0; y < C; ++y)
                {
                    int sum = 0;
                    int count = 0;
                    for (int i = -1; i <= 1; ++i)
                        for (int j = -1; j <= 1; ++j)
                            if (in_range(x + i, y + j))
                            {
                                sum += img[x + i][y + j];
                                ++count;
                            }
                    res[x][y] = sum / count;
                }

            return res;
        }
    };
}
