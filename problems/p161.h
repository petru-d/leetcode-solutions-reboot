#pragma once
#include <string>

namespace p161
{
    class Solution
    {
      public:
        bool isOneEditDistance(std::string s, std::string t)
        {
            if (s.size() > t.size())
                std::swap(s, t);

            if (t.size() - s.size() >= 2)
                return false;

            int currCost = 0;

            int currS = 0;
            int currT = 0;
            while (currT < t.size())
            {
                if (currS == s.size())
                {
                    ++currCost;
                    if (currCost > 1)
                        return false;
                    ++currT;
                    continue;
                }

                if (s[currS] == t[currT])
                {
                    ++currS;
                    ++currT;
                }
                else
                {
                    ++currCost;
                    if (currCost > 1)
                        return false;

                    if (s.size() == t.size())
                    {
                        ++currS;
                        ++currT;
                    }
                    else
                    {
                        ++currT;
                    }
                }
            }

            return currCost == 1;
        }
    };
}
