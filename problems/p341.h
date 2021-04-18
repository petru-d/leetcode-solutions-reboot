#pragma once
#include <stack>
#include <variant>
#include <vector>

namespace p341
{
    class NestedInteger
    {
      public:
        NestedInteger(int i)
        {
            _data = i;
        }
        NestedInteger(std::vector<NestedInteger>&& children)
        {
            _data = children;
        }

        // Return true if this NestedInteger holds a single integer, rather than a nested list.
        bool isInteger() const
        {
            return nullptr != std::get_if<int>(&_data);
        }

        // Return the single integer that this NestedInteger holds, if it holds a single integer
        // The result is undefined if this NestedInteger holds a nested list
        int getInteger() const
        {
            if (!isInteger())
            {
                assert(false);
                return -1;
            }

            return std::get<int>(_data);
        }

        // Return the nested list that this NestedInteger holds, if it holds a nested list
        // The result is undefined if this NestedInteger holds a single integer
        const std::vector<NestedInteger>& getList() const
        {
            return std::get<std::vector<NestedInteger>>(_data);
        }

      private:
        std::variant<int, std::vector<NestedInteger>> _data;
    };

    class NestedIterator
    {
      public:
        NestedIterator(std::vector<NestedInteger>& nestedList)
        {
            if (!nestedList.empty())
            {
                _lists.push(&nestedList);
                _positions.push(0);
            }
            advance();
        }

        int next()
        {
            int res = _stored;
            advance();

            return res;
        }

        bool hasNext()
        {
            return !_lists.empty();
        }

      private:
        void advance()
        {
            if (_lists.empty())
                return;

            if (_lists.top()->size() > _positions.top() && (*_lists.top())[_positions.top()].isInteger())
            {
                _stored = (*_lists.top())[_positions.top()].getInteger();
                ++_positions.top();
                return;
            }

            if (_lists.top()->size() <= _positions.top())
            {
                _lists.pop();
                _positions.pop();
                if (_positions.empty())
                    return;

                ++_positions.top();
                return advance();
            }

            _lists.push(&(*_lists.top())[_positions.top()].getList());
            _positions.push(0);
            return advance();
        }

        std::stack<const std::vector<NestedInteger>*> _lists;
        std::stack<size_t> _positions;
        int _stored = -1;
    };

}
