#include "pch.h"

#include "../problems/p560.h"

TEST(p560, t0)
{
    p560::Solution s;

    std::vector<int> data = {1, 1, 1};

    int result = s.subarraySum(data, 2);

    EXPECT_EQ(result, 2);
}

TEST(p560, t1)
{
    p560::Solution s;

    std::vector<int> data = {1};

    int result = s.subarraySum(data, 0);

    EXPECT_EQ(result, 0);
}
