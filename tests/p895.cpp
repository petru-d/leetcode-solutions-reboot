#include "pch.h"

#include "../problems/p895.h"

TEST(p895, t0)
{
    p895::FreqStackMine fm;
    p895::FreqStackOana fo;

    fm.push(5);
    fm.push(7);
    fm.push(5);
    fm.push(7);
    fm.push(4);
    fm.push(5);
    fo.push(5);
    fo.push(7);
    fo.push(5);
    fo.push(7);
    fo.push(4);
    fo.push(5);

    auto res = fm.pop();
    EXPECT_EQ(res, 5);
    res = fo.pop();
    EXPECT_EQ(res, 5);
    res = fm.pop();
    EXPECT_EQ(res, 7);
    res = fo.pop();
    EXPECT_EQ(res, 7);
}
