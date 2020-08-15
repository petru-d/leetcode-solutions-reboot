#include "pch.h"

#include "../problems/p1200.h"

TEST(p1200, t0)
{
    p1200::Solution s;
    std::vector<int> arr = {1, 3, 6, 10, 15};
    auto res = s.minimumAbsDifference(arr);

    std::vector<std::vector<int>> expected = {{1, 3}};

    EXPECT_EQ(res, expected);
}
