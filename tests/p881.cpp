#include "pch.h"

#include "../problems/p881.h"

TEST(p881, t0)
{
     p881::Solution s;

     std::vector<int> people = {1, 2};

     auto res = s.numRescueBoats(people, 3);

     EXPECT_EQ(res, 1);
}
