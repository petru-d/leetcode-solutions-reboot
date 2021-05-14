#include "pch.h"

#include "../problems/p816.h"

TEST(p816, t0)
{
    p816::Solution s;
    auto res = s.ambiguousCoordinates("(123)");
    std::vector<std::string> expected = {"(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"};
    EXPECT_TRUE(std::is_permutation(res.begin(), res.end(), expected.begin(), expected.end()));
}
