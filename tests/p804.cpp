#include "pch.h"

#include "../problems/p804.h"

TEST(p804, t0)
{
    p804::Solution s;

    std::vector<std::string> words = {"gin", "zen", "gig", "msg"};
    auto res = s.uniqueMorseRepresentations(words);

    EXPECT_EQ(res, 2);
}
