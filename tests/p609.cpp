#include "pch.h"

#include "../problems/p609.h"

TEST(p609, t0)
{
    std::vector<std::string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)",
                                      "root 4.txt(efgh)"};
    p609::Solution s;
    auto res = s.findDuplicate(paths);

    for (auto& r : res)
        std::sort(r.begin(), r.end());
    std::sort(res.begin(), res.end());

    std::vector<std::vector<std::string>> exp_sorted = {{"root/4.txt", "root/a/2.txt", "root/c/d/4.txt"},
                                                        {"root/a/1.txt", "root/c/3.txt"}};

    EXPECT_EQ(res, exp_sorted);
}
