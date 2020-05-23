#pragma once
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace p347
{
    class Solution
    {
      public:
        std::vector<int> topKFrequent(std::vector<int>& nums, int k)
        {
            if (k >= nums.size())
                return std::move(nums);

            std::unordered_map<int, size_t> element_to_frequency;
            for (auto n : nums)
            {
                auto f = ++element_to_frequency[n];
            }

            std::vector<int> top_k_frequencies; // min heap by frequency
            top_k_frequencies.reserve(static_cast<size_t>(k));
            std::unordered_set<int> top_k_elements;

            auto min_heap_by_frequency = [&element_to_frequency](int left, int right) {
                size_t freq_left = element_to_frequency[left];
                size_t freq_right = element_to_frequency[right];

                return freq_left > freq_right;
            };

            bool good_heap = true;

            for (auto [e, f] : element_to_frequency)
            {
                // already in top k
                if (top_k_elements.count(e) >= 1)
                {
                    good_heap = false;
                    continue;
                }

                // not in top k, but there is place
                if (top_k_elements.size() < static_cast<size_t>(k))
                {
                    top_k_elements.insert(e);
                    top_k_frequencies.push_back(e);
                    good_heap = false;
                    continue;
                }

                if (!good_heap)
                {
                    std::make_heap(top_k_frequencies.begin(), top_k_frequencies.end(), min_heap_by_frequency);
                    good_heap = true;
                }

                // not frequent enough (yet) - nothing to do
                if (element_to_frequency[top_k_frequencies.front()] >= f)
                    continue;

                // final case: the element is more frequent than the heap head
                // push it into the heap and in the top k elements
                int to_expell = top_k_frequencies.front();
                top_k_elements.erase(to_expell);
                top_k_elements.insert(e);

                std::pop_heap(top_k_frequencies.begin(), top_k_frequencies.end(), min_heap_by_frequency);
                top_k_frequencies.back() = e;
                std::push_heap(top_k_frequencies.begin(), top_k_frequencies.end(), min_heap_by_frequency);
            }

            return top_k_frequencies;
        }
    };
}