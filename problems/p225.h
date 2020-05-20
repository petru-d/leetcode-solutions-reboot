#pragma once
#include <queue>

namespace p225
{
    class MyStack
    {
      public:
        /** Initialize your data structure here. */
        MyStack()
        {
        }

        /** Push element x onto stack. */
        void push(int x)
        {
            _q.push(x);
        }

        /** Removes the element on top of the stack and returns that element. */
        int pop()
        {
            return rotate(true);
        }

        /** Get the top element. */
        int top()
        {
            return rotate(false);
        }

        /** Returns whether the stack is empty. */
        bool empty()
        {
            return _q.empty();
        }

      private:
        int rotate(bool remove)
        {
            if (empty())
                return -1;

            size_t N = _q.size();

            for (size_t i = 0; i < N - 1; ++i)
            {
                int x = _q.front();
                _q.pop();
                _q.push(x);
            }

            int result = _q.front();
            _q.pop();
            if (!remove)
            {
                _q.push(result);
            }

            return result;
        }
        std::queue<int> _q;
    };

    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */
}