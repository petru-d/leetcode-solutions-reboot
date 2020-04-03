#include "pch.h"

#include "../problems/p61.h"
#include "../problems/util_linked_list.h"

TEST(P61, T0)
{
    p61::Solution s;

    auto* result = s.rotateRight(make_list({1, 2, 3, 4, 5}), 2);
    auto* expected = make_list({4, 5, 1, 2, 3});

    EXPECT_EQ(true, eq_lists(result, expected));
}

TEST(P61, T1)
{
    p61::Solution s;

    auto* result = s.rotateRight(make_list({0, 1, 2}), 4);
    auto* expected = make_list({2, 0, 1});

    EXPECT_EQ(true, eq_lists(result, expected));
}
