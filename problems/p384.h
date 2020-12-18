#pragma once
#include <vector>
#include <random>

namespace p384
{
    class Solution
    {
      public:
        Solution(std::vector<int>& nums) : _nums(nums), _shuffled(nums), _shuffledOK(false)
        {
            std::random_device rd;
            _gen = std::mt19937(rd());

            _distrib = std::uniform_int_distribution<>(0, int(_nums.size()) - 1);
        }

        /** Resets the array to its original configuration and return it. */
        std::vector<int> reset()
        {
            _shuffledOK = false;
            return _nums;
        }

        /** Returns a random shuffling of the array. */
        std::vector<int> shuffle()
        {
            if (_shuffledOK)
                return _shuffled;

            for (int i = 0; i <= _shuffled.size(); ++i)
            {
                int advance = _distrib(_gen);
                std::swap(_shuffled[0], _shuffled[size_t(advance)]);
            }

            _shuffledOK = true;
            return _shuffled;
        }

        std::vector<int> _nums;
        std::vector<int> _shuffled;
        bool _shuffledOK = false;

        std::mt19937 _gen;
        std::uniform_int_distribution<> _distrib;
    };

    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(nums);
     * vector<int> param_1 = obj->reset();
     * vector<int> param_2 = obj->shuffle();
     */
}
