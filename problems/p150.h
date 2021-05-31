#pragma once
#include <functional>
#include <optional>
#include <stack>
#include <string>
#include <vector>
namespace p150
{
    class Solution
    {
      public:
        int evalRPN(std::vector<std::string>& tokens)
        {
            auto get_op = [](const std::string& op) -> std::optional<std::function<int(int, int)>> {
                if (op == "*")
                    return std::multiplies<int>{};
                else if (op == "/")
                    return std::divides<int>{};
                else if (op == "+")
                    return std::plus<int>{};
                else if (op == "-")
                    return std::minus<int>{};
                return {};
            };

            std::stack<int> nums;
            for (const auto& t : tokens)
            {
                auto op = get_op(t);
                if (op)
                {
                    auto t2 = nums.top();
                    nums.pop();
                    auto t1 = nums.top();
                    nums.pop();
                    auto res = (*op)(t1, t2);
                    nums.push(res);
                }
                else
                {
                    nums.push(std::stoi(t));
                }
            }

            return nums.top();
        }
    };
}
