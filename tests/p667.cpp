#include "pch.h"
#include <unordered_set>

#include "../problems/p667.h"

TEST(p667, t0)
{
    p667::Solution s;
    auto res = s.constructArray(3, 1);

    std::unordered_set<int> diffs;
    for (size_t i = 1; i < res.size(); ++i)
        diffs.insert(std::abs(res[i] - res[i - 1]));

    EXPECT_EQ(diffs.size(), 1);
}
