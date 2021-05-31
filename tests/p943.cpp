#include "pch.h"

#include "../problems/p943.h"

TEST(p943, t0)
{
    std::vector<std::string> words = {"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
    p943::Solution s;
    auto res = s.shortestSuperstring(words);

    EXPECT_TRUE(res.size() == std::string("gctaagttcatgcatc").size());
    for (const auto& w : words)
    {
        EXPECT_TRUE(res.find(w) != std::string::npos);
    }
}
