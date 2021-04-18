#include "pch.h"

#include "../problems/p1348.h"

TEST(p1348, t0)
{
    p1348::TweetCounts tc;
    tc.recordTweet("3", 0);
    tc.recordTweet("3", 60);
    tc.recordTweet("3", 10);
    auto res = tc.getTweetCountsPerFrequency("minute", "3", 0, 59);

    EXPECT_EQ(res, (std::vector<int>{2}));
}
