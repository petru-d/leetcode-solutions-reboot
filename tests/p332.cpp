#include "pch.h"

#include "../problems/p332.h"

TEST(p332, t0)
{
    p332::Solution2 s;

    std::vector<std::vector<std::string>> tickets = {
        {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};

    auto it = s.findItinerary(tickets);
    std::vector<std::string> expected = {"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"};
    EXPECT_EQ(it, expected);
}

TEST(p332, t1)
{
    p332::Solution s;

    std::vector<std::vector<std::string>> tickets = {
        {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};

    auto it = s.findItinerary(tickets);
    std::vector<std::string> expected = {"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"};
    EXPECT_EQ(it, expected);
}
