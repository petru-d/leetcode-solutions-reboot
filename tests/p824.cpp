#include "pch.h"

#include "../problems/p824.h"

TEST(p824, t0)
{
    p824::Solution s;

    auto res = s.toGoatLatin("I speak Goat Latin");

    EXPECT_EQ(res, "Imaa peaksmaaa oatGmaaaa atinLmaaaaa");
}
