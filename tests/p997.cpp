#include "pch.h"

#include "../problems/p997.h"

TEST(p997, t0)
{
    p997::Solution s;

    std::vector<std::vector<int>> data = {{1, 2}};

    auto result = s.findJudge(2, data);

    EXPECT_EQ(result, 2);
}
