#pragma once

#include <bitset>

namespace p705
{
    class MyHashSet
    {
      public:
        /** Initialize your data structure here. */
        MyHashSet()
        {
        }

        void add(int key)
        {
            _data.set(key);
        }

        void remove(int key)
        {
            _data.reset(key);
        }

        /** Returns true if this set contains the specified element */
        bool contains(int key)
        {
            return _data[key];
        }

      private:
        std::bitset<1000001> _data = {};
    };

    /**
     * Your MyHashSet object will be instantiated and called as such:
     * MyHashSet* obj = new MyHashSet();
     * obj->add(key);
     * obj->remove(key);
     * bool param_3 = obj->contains(key);
     */
}
