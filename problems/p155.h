#pragma once
#include <algorithm>
#include <exception>
namespace p155
{
    class MinStack
    {
      public:
        MinStack()
        {
        }

        void push(int x)
        {
            auto* newNode = new Node{nullptr, nullptr, x, x};
            if (_head == nullptr)
            {
                _head = _tail = newNode;
            }
            else
            {
                _tail->_next = newNode;
                newNode->_prev = _tail;

                newNode->minVal = std::min(_tail->minVal, x);

                _tail = newNode;
            }
        }

        void pop()
        {
            if (nullptr == _head)
            {
                // throw std::exception("called pop on empty stack");
            }

            if (_head == _tail)
            {
                delete _head;
                _head = _tail = nullptr;
            }
            else
            {
                auto* prevTail = _tail->_prev;
                delete _tail;
                prevTail->_next = nullptr;
                _tail = prevTail;
            }
        }

        int top()
        {
            if (nullptr == _head)
            {
                // throw std::exception("called top on empty stack");
            }
            return _tail->val;
        }

        int getMin()
        {
            if (nullptr == _tail)
            {
                // throw std::exception("called getMin on empty stack");
            }
            return _tail->minVal;
        }

      private:
        struct Node
        {
            Node* _next;
            Node* _prev;

            int val;
            int minVal; // minimum value saw until here
        };

        Node* _head = nullptr;
        Node* _tail = nullptr;
    };
}