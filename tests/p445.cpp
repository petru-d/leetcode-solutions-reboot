#include "pch.h"

#include "../problems/p445.h"

TEST(p445, t0)
{
     p445::Solution s;

     auto* res = s.addTwoNumbers(make_list({7, 2, 4, 3}), make_list({5, 6, 4}));
     EXPECT_TRUE(eq_lists(res, make_list({7, 8, 0, 7})));
}
