#include "pch.h"

#include "../problems/challenge_14apr2020.h"

TEST(challenge_14apr2020, t0)
{
    challenge_14apr2020::Solution s;

    std::vector<std::vector<int>> shift = {{0, 1}, {1, 2}};
    auto result = s.stringShift("abc", shift);

    EXPECT_EQ(result, "cab");
}

TEST(challenge_14apr2020, t1)
{
    challenge_14apr2020::Solution s;

    std::vector<std::vector<int>> shift = {{1, 1}, {1, 1}, {0, 2}, {1, 3}};
    auto result = s.stringShift("abcdefg", shift);

    EXPECT_EQ(result, "efgabcd");
}

TEST(challenge_14apr2020, t2)
{
    challenge_14apr2020::Solution s;

    std::vector<std::vector<int>> shift = {{1, 4}, {0, 5}, {0, 4}, {1, 1}, {1, 5}};
    auto result = s.stringShift("mecsk", shift);

    EXPECT_EQ(result, "kmecs");
}

TEST(challenge_14apr2020, t3)
{
    challenge_14apr2020::Solution s;

    std::vector<std::vector<int>> shift = {{0, 7}, {1, 7}, {1, 0}, {1, 3}, {0, 3}, {0, 6}, {1, 2}};
    auto result = s.stringShift("wpdhhcj", shift);

    EXPECT_EQ(result, "hcjwpdh");
}
