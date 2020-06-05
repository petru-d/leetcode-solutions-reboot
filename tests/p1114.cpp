#include "pch.h"

#include "../problems/p1114.h"

#include <future>

TEST(p1114, t0)
{
    std::vector<int> accumulate_here;

    auto print_first = [&accumulate_here]() { accumulate_here.push_back(1); };
    auto print_second = [&accumulate_here]() { accumulate_here.push_back(2); };
    auto print_third = [&accumulate_here]() { accumulate_here.push_back(3); };

    p1114::Foo f;
    auto a1 = std::async(&p1114::Foo::first, &f, print_first);
    auto a2 = std::async(&p1114::Foo::second, &f, print_second);
    auto a3 = std::async(&p1114::Foo::third, &f, print_third);
    a1.wait();
    a2.wait();
    a3.wait();

    std::vector<int> expected = {1, 2, 3};

    EXPECT_EQ(accumulate_here, expected);
}