#include "pch.h"

#include "../problems/challenge_28apr2020.h"

TEST(challenge_28apr2020, t0)
{
    std::vector<int> data = {2, 3, 5};
    challenge_28apr2020::FirstUnique f(data);

    auto res = f.showFirstUnique();
    EXPECT_EQ(res, 2);

    f.add(5);

    res = f.showFirstUnique();
    EXPECT_EQ(res, 2);

    f.add(2);

    res = f.showFirstUnique();
    EXPECT_EQ(res, 3);

    f.add(3);

    res = f.showFirstUnique();
    EXPECT_EQ(res, -1);
}

TEST(challenge_28apr2020, t1)
{
    std::vector<int> data = {7, 7, 7, 7, 7, 7};
    challenge_28apr2020::FirstUnique f(data);

    auto res = f.showFirstUnique();
    EXPECT_EQ(res, -1);

    f.add(7);
    f.add(3);
    f.add(3);
    f.add(7);
    f.add(17);

    res = f.showFirstUnique();
    EXPECT_EQ(res, 17);
}

TEST(challenge_28apr2020, t2)
{
    std::vector<int> data = {809};
    challenge_28apr2020::FirstUnique f(data);

    auto res = f.showFirstUnique();
    EXPECT_EQ(res, 809);

    f.add(809);

    res = f.showFirstUnique();
    EXPECT_EQ(res, -1);
}

TEST(challenge_28apr2020, t3)
{
    std::vector<int> data = {28, 28};

    challenge_28apr2020::FirstUnique f(data);

    f.add(28);

    auto res = f.showFirstUnique();
    EXPECT_EQ(res, -1);
}