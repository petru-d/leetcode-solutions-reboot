#pragma once
#include <vector>
#include <stack>

namespace p1306
{
    class Solution
    {
      public:
        bool canReach(std::vector<int>& arr, int start)
        {
            size_t A = arr.size();
            if (A == 0)
                return false;

            std::vector<int> visited(A, 0);

            std::stack<size_t> to_visit;
            to_visit.push(size_t(start));

            while (!to_visit.empty())
            {
                auto v = to_visit.top();
                if (arr[v] == 0)
                    return true;

                to_visit.pop();

                visited[v] = 1;

                if (v >= arr[v] && visited[v - arr[v]] == 0)
                    to_visit.push(v - arr[v]);
                if (v + arr[v] < A && visited[v + arr[v]] == 0)
                    to_visit.push(v + arr[v]);
            }

            return false;
        }
    };

}
