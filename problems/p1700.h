#pragma once
#include <vector>

namespace p1700
{
    class Solution
    {
      public:
        int countStudents(std::vector<int>& students, std::vector<int>& sandwiches)
        {
            // students can be viewed as a homogenous blob
            size_t zero_students = 0;
            size_t one_students = 0;
            for (const auto s : students)
                s == 0 ? ++zero_students : ++one_students;

            auto S = sandwiches.size();
            for (size_t i = 0; i < S; ++i)
            {
                if (sandwiches[i] == 0)
                {
                    if (zero_students == 0)
                        return int(S - i);
                    --zero_students;
                }
                else
                {
                    if (one_students == 0)
                        return int(S - i);
                    --one_students;
                }
            }

            return 0;
        }
    };
}
