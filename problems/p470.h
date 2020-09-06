#pragma once

namespace p470
{
    int rand7()
    {
        return 5;
    }

    class Solution
    {
        // nicer approach: roll 4 times, get a number between 1 and 2401 (including). if rolled 2401, try again, otherwise for
        // 1->240 return 1, 241->480 return 2 etc
        // or : roll 2 times, get a number betwen 1 and 49(including). if rolled 41 to 49 try again, otherwise 1->4 return 1 etc

      public:
        int rand10()
        {
            int sum = 0;
            for (int i = 0; i < 10; ++i)
                sum += rand7();

            return 1 + (sum % 10);
        }
    };
}
