#pragma once
#include <algorithm>
#include <vector>

namespace p1130
{
    class Solution
    {
      public:
        // idea: we need to remove all items in the array while minimizing the cost
        // - to remove one element, the cost is element * min(l, r)
        // - if an element is smller than both its l and r (aka local minimum), then its cost never going to be smaller than
        // element * min(l, r)

        // to implement:
        // - traverse the array in search of local minimas and remove them as much as possible
        // - after that, there won't be any more local minima and the array will be strictly descending. just remove elements from
        // least to biggest. (interestingly enough, if the array is strictly descending, elements can also be grouped from the
        // front to bottomn, the result is the same)

        int mctFromLeafValues(std::vector<int>& arr)
        {
            int res = 0;
            std::vector<int> stack = {INT_MAX};
            for (int a : arr)
            {
                // local minimum found
                while (stack.back() <= a)
                {
                    int mid = stack.back();
                    stack.pop_back();
                    res += mid * std::min(stack.back(), a);
                }
                stack.push_back(a);
            }

            while (stack.size() > 2)
            {
                int last = stack.back();
                stack.pop_back();
                res += last * stack.back();
            }

            return res;
        }
    };
}