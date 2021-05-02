#include "pch.h"

#include "../problems/p630.h"

TEST(p630, t0)
{
    p630::Solution s;

    std::vector<std::vector<int>> courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    auto res = s.scheduleCourse(courses);
    EXPECT_EQ(res, 3);
}
