#include "pch.h"

#include "../problems/p870.h"

TEST(p870, t0)
{
    p870::Solution s;
    std::vector<int> A{2, 7, 11, 15};
    std::vector<int> B{1, 10, 4, 11};
    auto res = s.advantageCount(A, B);

    std::vector<int> exp{2, 11, 7, 15};

    EXPECT_TRUE(std::is_permutation(res.begin(), res.end(), exp.begin()));
}
