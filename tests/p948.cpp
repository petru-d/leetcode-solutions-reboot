#include "pch.h"

#include "../problems/p948.h"

TEST(p948, t0)
{
    p948::Solution s;

    std::vector<int> tokens = {100};

    auto res = s.bagOfTokensScore(tokens, 50);

    EXPECT_EQ(res, 0);
}

TEST(p948, t1)
{
    p948::Solution s;

    std::vector<int> tokens = {100, 200};

    auto res = s.bagOfTokensScore(tokens, 150);

    EXPECT_EQ(res, 1);
}

TEST(p948, t2)
{
    p948::Solution s;

    std::vector<int> tokens = {100, 200, 300, 400};

    auto res = s.bagOfTokensScore(tokens, 200);

    EXPECT_EQ(res, 2);
}
