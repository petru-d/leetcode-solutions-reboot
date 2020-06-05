#include "pch.h"

#include "../problems/p1117.h"

#include <future>

TEST(p1117, t0)
{
    std::multiset<char> accumulate_here;

    auto emit_hydrogen = [&accumulate_here]() { accumulate_here.insert('H'); };
    auto emit_oxygen = [&accumulate_here]() { accumulate_here.insert('O'); };

    p1117::H2O h2o;
    auto h1 = std::async(&p1117::H2O::hydrogen, &h2o, emit_hydrogen);
    auto h2 = std::async(&p1117::H2O::hydrogen, &h2o, emit_hydrogen);
    auto o = std::async(&p1117::H2O::oxygen, &h2o, emit_oxygen);
    h1.wait();
    h2.wait();
    o.wait();

    auto h_count = accumulate_here.count('H');
    auto o_count = accumulate_here.count('O');

    EXPECT_EQ(h_count, 2);
    EXPECT_EQ(o_count, 1);
}