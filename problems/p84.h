#pragma once
#include <vector>
#include <stack>

namespace p84
{
    class Solution
    {
      public:
        int largestRectangleArea(std::vector<int>& heights)
        {
            std::stack<size_t> s;
            s.push(-1);
            auto L = int(heights.size());

            int maxArea = 0;

            for (int i = 0; i < L; i++)
            {
                while ((s.top() != -1) && (heights[s.top()] >= heights[i]))
                {
                    auto h = heights[s.top()];
                    s.pop();

                    int w = i - int(s.top()) - 1;
                    maxArea = std::max(maxArea, h * w);
                }
                s.push(i);
            }

            while (s.top() != -1)
            {
                int h = heights[s.top()];
                s.pop();
                int w = L - int(s.top()) - 1;
                maxArea = std::max(maxArea, h * w);
            }

            return maxArea;
        }
    };
}
