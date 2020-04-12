#include "pch.h"

#include "../problems/p1175.h"

TEST(p1175, t0)
{
    p1175::Solution s;
    auto result = s.numPrimeArrangements(5);

    EXPECT_EQ(result, 12);
}

TEST(p1175, t1)
{
    p1175::Solution s;
    auto result = s.numPrimeArrangements(100);

    EXPECT_EQ(result, 682289015);
}
