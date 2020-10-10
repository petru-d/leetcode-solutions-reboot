#pragma once
#include <string>
#include <vector>
namespace p1598
{
    class Solution
    {
      public:
        int minOperations(std::vector<std::string>& logs)
        {
            size_t level = 0;

            for (const auto& l : logs)
            {
                if (l == "../")
                {
                    if (level > 0)
                        --level;
                    continue;
                }

                if (l == "./")
                    continue;

                ++level;
            }

            return int(level);
        }
    };
}
