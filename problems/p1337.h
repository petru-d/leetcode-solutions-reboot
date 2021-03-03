#pragma once
#include <queue>
#include <vector>
namespace p1337
{
    class Solution
    {
      public:
        std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k)
        {
            using PSS = std::pair<size_t, size_t>;

            std::priority_queue<PSS> q;

            for (size_t r = 0; r < mat.size(); ++r)
            {
                size_t soldiers = 0;
                for (size_t c = 0; c < mat[r].size(); ++c)
                    if (mat[r][c] == 1)
                        ++soldiers;
                    else
                        break;

                q.push({soldiers, r});
                if (q.size() > k)
                    q.pop();
            }

            std::vector<int> result(k, 0);
            size_t curr = result.size();
            while (!q.empty())
            {
                auto [s, r] = q.top();
                result[--curr] = r;
                q.pop();
            }

            return result;
        }
    };
}
