#include "pch.h"

#include "../problems/p1576.h"

TEST(p1576, t0)
{
    p1576::Solution s;

    auto res = s.modifyString("?zs");

    auto is_good = [](const std::string& s) {
        auto S = s.size();
        for (size_t i = 1; i < S; ++i)
            if (s[i - 1] == s[i])
                return false;
        return true;
    };

    EXPECT_TRUE(is_good(res));
}
