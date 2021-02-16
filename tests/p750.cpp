#include "pch.h"

#include "../problems/p750.h"

TEST(p750, t0)
{
     p750::Solution s;

     std::vector<std::vector<int>> grid = {
         {1, 1, 1},
         {1, 1, 1},
         {1, 1, 1}
     };

     auto res= s.countCornerRectangles(grid);

     EXPECT_EQ(res, 9);
}
