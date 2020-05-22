#include "pch.h"

#include "../problems/p401.h"

TEST(p401, t0)
{
    p401::Solution s;
    auto res = s.readBinaryWatch(1);
    std::set<std::string> res_set;
    std::transform(res.begin(), res.end(), std ::inserter(res_set, res_set.end()), [](std::string s) { return s; });

    std::set<std::string> expected = {"0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00"};

    EXPECT_EQ(res_set, expected);
}

TEST(p401, t1)
{
    p401::Solution s;
    auto res = s.readBinaryWatch(2);
    std::set<std::string> res_set;
    std::transform(res.begin(), res.end(), std ::inserter(res_set, res_set.end()), [](std::string s) { return s; });

    std::set<std::string> expected = {"0:03", "0:05", "0:06", "0:09", "0:10", "0:12", "0:17", "0:18", "0:20", "0:24", "0:33",
                                      "0:34", "0:36", "0:40", "0:48", "1:01", "1:02", "1:04", "1:08", "1:16", "1:32", "2:01",
                                      "2:02", "2:04", "2:08", "2:16", "2:32", "3:00", "4:01", "4:02", "4:04", "4:08", "4:16",
                                      "4:32", "5:00", "6:00", "8:01", "8:02", "8:04", "8:08", "8:16", "8:32", "9:00", "10:00"};

    EXPECT_EQ(res_set, expected);
}
