#include "pch.h"

#include "../problems/p83.h"
#include "../problems/util_linked_list.h"

TEST(P83, T0)
{
    p83::Solution s;

    auto* result = s.deleteDuplicates(make_list({1, 1, 2}));
    auto* expected = make_list({1, 2});

    EXPECT_EQ(true, eq_lists(result, expected));
}

TEST(P83, T1)
{
    p83::Solution s;

    auto* result = s.deleteDuplicates(make_list({1, 1, 2, 3, 3}));
    auto* expected = make_list({1, 2, 3});

    EXPECT_EQ(true, eq_lists(result, expected));
}

TEST(P83, T2)
{
    p83::Solution s;

    auto* result = s.deleteDuplicates(make_list({1, 1, 1, 1, 1}));
    auto* expected = make_list({1});

    EXPECT_EQ(true, eq_lists(result, expected));
}
