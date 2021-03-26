#pragma once
#include <algorithm>
#include <vector>

namespace p870
{
    class Solution
    {
      public:
        std::vector<int> advantageCount(std::vector<int>& A, std::vector<int>& B)
        {
            auto S = A.size();

            std::vector<std::pair<int, size_t>> BWithIndices;
            BWithIndices.reserve(S);
            for (size_t i = 0; i < S; ++i)
            {
                BWithIndices.emplace_back(B[i], i);
            }

            std::sort(BWithIndices.begin(), BWithIndices.end(), [](const auto& l, const auto& r) { return l.first < r.first; });

            std::vector<int> result(S, 0);

            // make a min heap with A
            // for each element in sorted B, pop heap until we can cover it
            // when the heap is empty, we covered the maximum number of elements from B
            // fill the rest of the result with the elements that were popped without covering anything

            std::make_heap(A.begin(), A.end(), std::greater<>{});
            std::vector<int> discarded;
            std::vector<int> filled(S, 0);
            for (size_t i = 0; i < S; ++i)
            {
                if (A.empty())
                    break;

                auto [bVal, bIndex] = BWithIndices[i];
                int heap_top = -1;
                while (!A.empty() && heap_top <= bVal)
                {
                    std::pop_heap(A.begin(), A.end(), std::greater<>{});
                    heap_top = A.back();
                    A.pop_back();
                    if (heap_top <= bVal)
                        discarded.push_back(heap_top);
                    else
                    {
                        result[bIndex] = heap_top;
                        filled[bIndex] = 1;
                    }
                }
            }

            // if there's any indices from B which we did not cover, fill them now with the discarded stuff
            for (size_t i = 0; i < S; ++i)
            {
                if (filled[i] == 1)
                    continue;
                result[i] = discarded.back();
                discarded.pop_back();
            }

            return result;
        }
    };
}
