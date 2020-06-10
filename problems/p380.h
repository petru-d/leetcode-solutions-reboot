#pragma once

#include <random>
#include <unordered_map>
#include <vector>

namespace p380
{
    class RandomizedSet
    {
      public:
        /** Initialize your data structure here. */
        RandomizedSet()
        {
        }

        /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
        bool insert(int val)
        {
            auto pos = _numbers_to_indices.find(val);
            if (pos != _numbers_to_indices.end())
                return false;

            _numbers_vector.push_back(val);
            _numbers_to_indices.insert({val, _numbers_vector.size() - 1});

            _random_ready = false;
            return true;
        }

        /** Removes a value from the set. Returns true if the set contained the specified element. */
        bool remove(int val)
        {
            auto pos = _numbers_to_indices.find(val);
            if (pos == _numbers_to_indices.end())
                return false;

            size_t index_remove = pos->second;

            size_t index_last = _numbers_vector.size() - 1;
            int value_last = _numbers_vector.back();

            if (index_remove != index_last)
            {
                _numbers_to_indices[value_last] = index_remove;
                std::swap(_numbers_vector[index_remove], _numbers_vector[index_last]);
            }

            _numbers_to_indices.erase(val);
            _numbers_vector.pop_back();

            _random_ready = false;
            return true;
        }

        /** Get a random element from the set. */
        int getRandom()
        {
            if (_numbers_vector.empty())
                return -1;

            if (!_random_ready)
            {
                std::random_device rd;
                _gen = std::mt19937(rd());
                _distrib = std::uniform_int_distribution<size_t>(0, _numbers_vector.size() - 1);
                _random_ready = true;
            }

            return _numbers_vector[_distrib(_gen)];
        }

      private:
        // keep the numbers, mapped to their indices in the vector.
        std::unordered_map<int, size_t> _numbers_to_indices;

        // keep the numbers again, for easy randomization;
        std::vector<int> _numbers_vector;

        bool _random_ready = false;
        std::mt19937 _gen;
        std::uniform_int_distribution<size_t> _distrib;
    };
}
