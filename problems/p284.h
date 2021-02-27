#pragma once
#include <vector>

namespace p284
{
    struct Data
    {
        const std::vector<int>& v;
        Data(const std::vector<int>& vv) : v(vv)
        {
        }
    };

    class Iterator
    {
        p284::Data* data;

        size_t pos = 0;

      public:
        Iterator(const std::vector<int>& nums)
        {
            data = new Data(nums);
        }
        Iterator(const Iterator& iter)
        {
        }
        // Returns the next element in the iteration.
        int next()
        {
            return data->v[pos++];
        }
        // Returns true if the iteration has more elements.
        bool hasNext() const
        {
            return pos < data->v.size() - 1;
        }
    };

    class PeekingIterator : public Iterator
    {
      public:
        PeekingIterator(const std::vector<int>& nums) : Iterator(nums)
        {
        }

        // Returns the next element in the iteration without advancing the iterator.
        int peek()
        {
            if (_hasPeaked)
                return _peakVal;

            _hasPeaked = true;
            return _peakVal = Iterator::next();
        }

        // hasNext() and next() should behave the same as in the Iterator interface.
        // Override them if needed.
        int next()
        {
            if (_hasPeaked)
            {
                _hasPeaked = false;
                return _peakVal;
            }

            return Iterator::next();
        }

        bool hasNext() const
        {
            return _hasPeaked || Iterator::hasNext();
        }

        bool _hasPeaked = false;
        int _peakVal = -1;
    };
}
