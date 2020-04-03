#include "pch.h"

#include "../problems/p136.h"

template <typename T> int get_result(vector<int>& nums)
{
    T s;
    return s.singleNumber(nums);
}

TEST(p136, T0)
{
    vector<int> nums = {2, 2, 1};

    auto result = get_result<code_chall_1_p1::Solution>(nums);
    EXPECT_EQ(result, 1);

    result = get_result<code_chall_1_p1::Solution_stolen>(nums);
    EXPECT_EQ(result, 1);
}

TEST(p136, T1)
{
    vector<int> nums = {4, 1, 2, 1, 2};

    auto result = get_result<code_chall_1_p1::Solution>(nums);
    EXPECT_EQ(result, 4);

    result = get_result<code_chall_1_p1::Solution_stolen>(nums);
    EXPECT_EQ(result, 4);
}
