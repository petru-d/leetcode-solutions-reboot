#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace p1348
{
    class TweetCounts
    {
      public:
        TweetCounts()
        {
        }

        void recordTweet(std::string tweetName, int time)
        {
            _tweet_to_times[tweetName].push_back(time);
        }

        std::vector<int> getTweetCountsPerFrequency(std::string freq, std::string tweetName, int startTime, int endTime)
        {
            auto increment = get_increment(freq);

            // bucket [start, start + increment)
            std::vector<int> bucket_quants((endTime - startTime) / increment + 1, 0);
            const auto& times = _tweet_to_times[tweetName];
            for (const auto t : times)
            {
                if (t < startTime || t > endTime)
                    continue;

                ++bucket_quants[(t - startTime) / increment];
            }

            return bucket_quants;
        }

      private:
        int get_increment(const std::string& freq)
        {
            if (freq == "minute")
                return 60;
            if (freq == "hour")
                return 3600;
            if (freq == "day")
                return 86400;

            assert(false);
            return -1;
        }

        std::unordered_map<std::string, std::vector<int>> _tweet_to_times;
    };

    /**
     * Your TweetCounts object will be instantiated and called as such:
     * TweetCounts* obj = new TweetCounts();
     * obj->recordTweet(tweetName,time);
     * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
     */
}
