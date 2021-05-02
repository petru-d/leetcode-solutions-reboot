#include "pch.h"

#include "../problems/p745.h"

TEST(p745, t0)
{
    std::vector<std::string> words = {"apple"};
    p745::WordFilter w(words);
    words = {"apple"};
    p745::WordFilter2 w2(words);
    words = {"apple"};
    p745::WordFilter3 w3(words);

    auto res = w.f("a", "e");
    EXPECT_EQ(res, 0);
    res = w2.f("a", "e");
    EXPECT_EQ(res, 0);
    res = w3.f("a", "e");
    EXPECT_EQ(res, 0);
}
