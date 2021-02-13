#include "pch.h"

#include "../problems/p1700.h"

TEST(p1700, t0)
{
     p1700::Solution s;

     std::vector<int> students = {1, 1, 1, 0, 0, 1};
     std::vector<int> sandwiches = {1, 0, 0, 0, 1, 1};

     auto res = s.countStudents(students, sandwiches);

     EXPECT_EQ(res, 3);
}
