#include "pch.h"

#include "../problems/p1268.h"

TEST(p1268, t0)
{
    std::vector<std::string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};

    std::vector<std::vector<std::string>> expected = {{"mobile", "moneypot", "monitor"},
                                                      {"mobile", "moneypot", "monitor"},
                                                      {"mouse", "mousepad"},
                                                      {"mouse", "mousepad"},
                                                      {"mouse", "mousepad"}};

    p1268::Solution s;
    auto res = s.suggestedProducts(products, "mouse");
    EXPECT_EQ(res, expected);

    p1268::Solution2 s2;
    auto res2 = s2.suggestedProducts(products, "mouse");
    EXPECT_EQ(res2, expected);
}
