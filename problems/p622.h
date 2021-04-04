#pragma once
#include <vector>

namespace p622
{
    class MyCircularQueue
    {
      public:
        MyCircularQueue(int k) : _buffer(k, 0), _head(0), _tail(0), _full(false)
        {
        }

        bool enQueue(int value)
        {
            if (isFull())
                return false;

            _buffer[_tail] = value;
            _tail = (_tail + 1) % _buffer.size();

            if (_tail == _head)
                _full = true;

            return true;
        }

        bool deQueue()
        {
            if (isEmpty())
                return false;

            _head = (_head + 1) % _buffer.size();

            _full = false;

            return true;
        }

        int Front()
        {
            if (isEmpty())
                return -1;
            return _buffer[_head];
        }

        int Rear()
        {
            if (isEmpty())
                return -1;

            return _tail == 0 ? _buffer.back() : _buffer[_tail - 1];
        }

        bool isEmpty()
        {
            return _head == _tail && !_full;
        }

        bool isFull()
        {
            return _full;
        }

        std::vector<int> _buffer;
        size_t _head = -1;
        size_t _tail = -1;
        bool _full = false;
    };
}
