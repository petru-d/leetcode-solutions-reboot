#pragma once
#include <array>

namespace p706
{
    class MyHashMap
    {
      public:
        /** Initialize your data structure here. */
        MyHashMap()
        {
            std::fill(_data.begin(), _data.end(), -1);
        }

        /** value will always be non-negative. */
        void put(int key, int value)
        {
            _data[key] = value;
        }

        /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
        int get(int key)
        {
            return _data[key];
        }

        /** Removes the mapping of the specified value key if this map contains a mapping for the key */
        void remove(int key)
        {
            _data[key] = -1;
        }

        std::array<uint32_t, 1000001> _data;
    };
}
