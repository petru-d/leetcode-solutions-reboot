#include "pch.h"

#include "../problems/p49.h"

TEST(P49, T0)
{
    p49::Solution s;

    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    auto result = s.groupAnagrams(strs);

    std::vector<std::vector<std::string>> expected = {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};

    // for each member (R) of result, there exists exactly one (E) in expected such that R is a permutation of E

    for (const auto& r : result)
    {
        size_t perm_count = 0;
        for (const auto& e : expected)
        {
            if (std::is_permutation(r.begin(), r.end(), e.begin(), e.end()))
                ++perm_count;
        }
        EXPECT_EQ(perm_count, 1);
    }
}
