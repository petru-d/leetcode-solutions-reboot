#pragma once
#include <stack>
#include <vector>

namespace p946
{
    class Solution
    {
      public:
        bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped)
        {
            if (pushed.empty())
                return popped.empty();

            std::stack<int> simulation;

            simulation.push(pushed[0]);
            size_t pos_pushed = 1;
            size_t pos_popped = 0;

            auto can_pop = [&]() {
                if (simulation.empty() || pos_popped >= popped.size())
                    return false;
                return simulation.top() == popped[pos_popped];
            };
            auto can_push = [&]() { return pos_pushed < pushed.size(); };
            auto push = [&]() { simulation.push(pushed[pos_pushed++]); };
            auto pop = [&]() {
                simulation.pop();
                ++pos_popped;
            };

            while (pos_pushed < pushed.size() || pos_popped < popped.size())
            {
                if (!can_pop())
                {
                    if (!can_push())
                        return false;
                    push();
                }
                else
                {
                    pop();
                }
            }

            return true;
        }
    };
}
