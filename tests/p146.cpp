#include "pch.h"

#include "../problems/p146.h"

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

TEST(p146, t0)
{
    p146::LRUCache obj(2);

    int res;

    obj.put(1, 1);
    obj.put(2, 2);
    res = obj.get(1);
    EXPECT_EQ(res, 1);
    obj.put(3, 3);
    res = obj.get(2);
    EXPECT_EQ(res, -1);
    obj.put(4, 4);
    res = obj.get(1);
    EXPECT_EQ(res, -1);
    res = obj.get(3);
    EXPECT_EQ(res, 3);
    res = obj.get(4);
    EXPECT_EQ(res, 4);
}

TEST(p146, t1)
{
    p146::LRUCache obj(1);

    int res;

    obj.put(2, 1);
    res = obj.get(2);
    EXPECT_EQ(res, 1);
    obj.put(3, 2);
    res = obj.get(2);
    EXPECT_EQ(res, -1);
    res = obj.get(3);
    EXPECT_EQ(res, 2);
}

TEST(p146, t2)
{
    p146::LRUCache obj(2);

    int res;

    obj.put(2, 1);
    obj.put(2, 2);
    res = obj.get(2);
    EXPECT_EQ(res, 2);
    obj.put(1, 1);
    obj.put(4, 1);
    res = obj.get(2);
    EXPECT_EQ(res, -1);
}

TEST(p146, t3)
{
    p146::LRUCache obj(2);

    int res;

    res = obj.get(2);
    EXPECT_EQ(res, -1);

    obj.put(2, 6);

    res = obj.get(1);
    EXPECT_EQ(res, -1);

    obj.put(1, 5);
    obj.put(1, 2);

    res = obj.get(1);
    EXPECT_EQ(res, 2);

    res = obj.get(2);
    EXPECT_EQ(res, 6);
}