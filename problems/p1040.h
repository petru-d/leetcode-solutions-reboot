#pragma once
#include <algorithm>
#include <vector>

namespace p1040
{
    class Solution
    {
      public:
        std::vector<int> numMovesStonesII(std::vector<int>& stones)
        {
            size_t N = stones.size();
            if (N <= 2)
                return {0, 0};

            std::sort(stones.begin(), stones.end());

            // each time we move, the diameter of the collection shrinks by a non zero amount

            int initial_diameter = 1 + stones[N - 1] - stones[0];
            // if we have a continuous block of stones, the game is already over
            if (initial_diameter == N)
                return {0, 0};

            // to get the maximum number of moves: move the first stone such that we get the least amount of shrinkage:
            // this will be min (s[1] - s[0], s[n-1] - s[n-2]) (just move the stone near the first after/before it)
            // after this, we can decrease the diameter by exactly one each move (we have at at least one range two stones near
            // eachother - move the external immediatelly inside)
            int diameter_after_first_move = initial_diameter - std::min(stones[1] - stones[0], stones[N - 1] - stones[N - 2]);
            size_t max_moves = 1 + diameter_after_first_move - N;

            // to get the minimum number of moves: find the window of size N that contains the most elements and it either starts
            // or ends with an element.
            // evey element will jump in that window, so the minimum number of moves is N - number of
            // elements already in the window.

            // why it works: the window already has one element in an edge. the first move is to jump with any external stone in
            // the other edge of the window. All subsequent moves simply jump in the window until it is full. edge case: the first
            // move is not possible as described. example case: [3 4 5 6 10]. In this case, the min number of moves is 2.

            // additionally: we can actually consider only windows that start with an element and end on or after an element.
            // proof: assume that the best window ends in an element and starts before an element (distance d). then
            // - either we can slide it freely to the right so that it starts with an element and ends after the last element
            // (distance d) with no change
            // - other when we slide it left, we encounter another element before d is over - then we found a better window -
            // contradition
            size_t l = 0, r = 1, min_moves = stones.size();
            while (r < stones.size())
            {
                size_t interval = static_cast<size_t>(stones[r]) - stones[l] - (r - l);
                size_t numStoneOutsideLR = stones.size() - (r - l + size_t(1));
                if (numStoneOutsideLR >= interval)
                {
                    if (numStoneOutsideLR == 1 && interval == 0)
                        min_moves = std::min(min_moves, size_t(2)); // shit corner case
                    else
                        min_moves = std::min(min_moves, numStoneOutsideLR);
                    r++;
                }
                else
                {
                    l++;
                }
            };

            return {static_cast<int>(min_moves), static_cast<int>(max_moves)};
        }
    };
}
