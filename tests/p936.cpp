#include "pch.h"

#include "../problems/p936.h"

TEST(p936, t0)
{
    p936::Solution s;

    std::string stamp("abca");
    std::string target("aabcaca");

    auto res = s.movesToStamp(stamp, target);

    // the only correct way to verify is to stamp forwards
    std::string initial = "???????";
    for (auto r : res)
    {
        std::copy(stamp.begin(), stamp.end(), initial.begin() + r);
    }
    EXPECT_EQ(initial, target);
}
