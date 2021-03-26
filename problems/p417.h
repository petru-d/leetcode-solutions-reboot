#pragma once
#include <vector>

namespace p417
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& matrix)
        {
            if (matrix.empty() || matrix.front().empty())
                return {};

            Matrix = std::move(matrix);
            Rows = Matrix.size();
            Cols = Matrix.front().size();

            std::vector<std::vector<int>> PacificFlow(Rows, std::vector<int>(Cols, 0));
            auto AtlanticFlow = PacificFlow;

            for (size_t i = 0; i < Rows; ++i)
            {
                if (PacificFlow[i][0] == 0)
                    flow(PacificFlow, i, 0);
                if (AtlanticFlow[i][Cols - 1] == 0)
                    flow(AtlanticFlow, i, Cols - 1);
            }
            for (size_t j = 0; j < Cols; ++j)
            {
                if (PacificFlow[0][j] == 0)
                    flow(PacificFlow, 0, j);
                if (AtlanticFlow[Rows - 1][j] == 0)
                    flow(AtlanticFlow, Rows - 1, j);
            }

            std::vector<std::vector<int>> result;
            for (size_t i = 0; i < Rows; ++i)
                for (size_t j = 0; j < Cols; ++j)
                    if (PacificFlow[i][j] == 1 && AtlanticFlow[i][j] == 1)
                        result.emplace_back(std::vector<int>{int(i), int(j)});
            return result;
        }

        void flow(std::vector<std::vector<int>>& Ocean, size_t i, size_t j)
        {
            Ocean[i][j] = 1;
            if (i > 0 && Ocean[i - 1][j] == 0 && Matrix[i - 1][j] >= Matrix[i][j])
                flow(Ocean, i - 1, j);
            if (i < Rows - 1 && Ocean[i + 1][j] == 0 && Matrix[i + 1][j] >= Matrix[i][j])
                flow(Ocean, i + 1, j);
            if (j > 0 && Ocean[i][j - 1] == 0 && Matrix[i][j - 1] >= Matrix[i][j])
                flow(Ocean, i, j - 1);
            if (j < Cols - 1 && Ocean[i][j + 1] == 0 && Matrix[i][j + 1] >= Matrix[i][j])
                flow(Ocean, i, j + 1);
        };

        size_t Rows = -1;
        size_t Cols = -1;
        std::vector<std::vector<int>> Matrix;
    };
}
