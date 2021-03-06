#include "pch.h"

#include "../problems/p876.h"

TEST(p876, t0)
{
    p876::Solution s;

    auto* list = make_list({1, 2, 3, 4, 5});
    auto result = s.middleNode(list);
    auto* expected = make_list({3, 4, 5});

    EXPECT_EQ(true, eq_lists(result, expected));
}

TEST(p876, t1)
{
    p876::Solution s;

    auto* list = make_list({1, 2, 3, 4, 5, 6});
    auto result = s.middleNode(list);
    auto* expected = make_list({4, 5, 6});

    EXPECT_EQ(true, eq_lists(result, expected));
}

TEST(p876, t2)
{
    p876::Solution s;

    auto* list = make_list({1});
    auto result = s.middleNode(list);
    auto* expected = make_list({1});

    EXPECT_EQ(true, eq_lists(result, expected));
}