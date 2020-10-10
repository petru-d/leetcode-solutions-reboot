#include "pch.h"

#include "../problems/p449.h"

TEST(p449, t0)
{
    p449::Codec s;

    auto tree = s.deserialize("2 1 3");

    std::string serialized = serialize_tree(tree);

    EXPECT_EQ(serialized, "2(1,3)");
}
