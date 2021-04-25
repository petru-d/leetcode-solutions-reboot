#include "pch.h"

#include "../problems/p253.h"

TEST(p253, t0)
{
    std::vector<std::vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};

    p253::Solution s;
    auto res = s.minMeetingRooms(intervals);
    EXPECT_EQ(res, 2);

    p253::Solution s2;
    auto res2 = s2.minMeetingRooms(intervals);
    EXPECT_EQ(res2, 2);
}
