#pragma once
#include <vector>

namespace p339
{
    // This is the interface that allows for creating nested lists.
    // You should not implement it, or speculate about its implementation
    class NestedInteger
    {
      public:
        // Constructor initializes an empty nested list.
        NestedInteger() = default;

        // Constructor initializes a single integer.
        NestedInteger(int value)
        {
            _integer = true;
            _val = value;
        }

        // Return true if this NestedInteger holds a single integer, rather than a nested list.
        bool isInteger() const
        {
            return _integer;
        }

        // Return the single integer that this NestedInteger holds, if it holds a single integer
        // The result is undefined if this NestedInteger holds a nested list
        int getInteger() const
        {
            return _val;
        }

        // Set this NestedInteger to hold a single integer.
        void setInteger(int value)
        {
            _integer = true;
            _val = value;
        }

        // Set this NestedInteger to hold a nested list and adds a nested integer to it.
        void add(const NestedInteger& ni)
        {
            _integer = false;
            _list.push_back(ni);
        }

        // Return the nested list that this NestedInteger holds, if it holds a nested list
        // The result is undefined if this NestedInteger holds a single integer
        const std::vector<NestedInteger>& getList() const
        {
            return _list;
        }

      private:
        std::vector<NestedInteger> _list;
        int _val = 0;
        bool _integer = false;
    };

    class Solution
    {
      public:
        int depthSum(std::vector<NestedInteger>& nestedList)
        {
            return depthSumC(nestedList, 1);
        }

        int depthSumC(const std::vector<NestedInteger>& nestedList, int depth)
        {
            int result = 0;
            for (const auto& ni : nestedList)
            {
                if (ni.isInteger())
                    result += depth * ni.getInteger();
                else
                    result += depthSumC(ni.getList(), depth + 1);
            }

            return result;
        }
    };
}
