#include "pch.h"

#include "../problems/p328.h"

TEST(p328, t0)
{
    p328::Solution s;

    auto* l = make_list(std::vector<int>{1, 2, 3, 4, 5});
    auto* result = s.oddEvenList(l);

    auto* expected = make_list(std::vector<int>{1, 3, 5, 2, 4});

    EXPECT_TRUE(eq_lists(result, expected));
}

TEST(p328, t1)
{
    p328::Solution s;

    auto* l = make_list(std::vector<int>{2, 1, 3, 5, 6, 4, 7});
    auto* result = s.oddEvenList(l);

    auto* expected = make_list(std::vector<int>{2, 3, 6, 7, 1, 5, 4});

    EXPECT_TRUE(eq_lists(result, expected));
}
