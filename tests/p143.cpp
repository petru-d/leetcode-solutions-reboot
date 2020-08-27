#include "pch.h"

#include "../problems/p143.h"

TEST(p143, t0)
{
    p143::Solution s;

    auto list = make_list(std::vector<int>{1, 2, 3, 4, 5});
    s.reorderList(list);

    EXPECT_TRUE(eq_lists(list, make_list(std::vector<int>{1, 5, 2, 4, 3})));
}
