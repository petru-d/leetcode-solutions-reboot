#include "pch.h"

#include "../problems/p1564.h"

TEST(p1564, t0)
{
    std::vector<int> boxes = {4, 3, 4, 1};
    std::vector<int> warehouse = {5, 3, 3, 4, 1};
    p1564::Solution s;
    auto res = s.maxBoxesInWarehouse(boxes, warehouse);
    EXPECT_EQ(res, 3);

    p1564::Solution2 s2;
    res = s2.maxBoxesInWarehouse(boxes, warehouse);
    EXPECT_EQ(res, 3);
}
