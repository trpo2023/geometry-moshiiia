#ifndef CIRCLE_TEST
#define CIRCLE_TEST

#include "circle.h"
#include <gtest/gtest.h>
#include <string>

TEST(CIRCLE, isIntersection)
{
    Circle arr[2];
   
    arr[0].center.x = 10;
    arr[0].center.y = 10;
    arr[0].radius = 10;

    arr[1].center.x = 10;
    arr[1].center.y = 9;
    arr[1].radius = 8;
    // bool a = isIntersection(arr, 2);
    // ASSERT_TRUE(a);
    // ASSERT_FALSE(a);


}

TEST(CIRCLE, validateCircle)
{
    std::string examp = "circle(10 10,10)";
    Circle circle1;

    int a = validateCircle(examp, circle1);
    ASSERT_EQ(a, 5);

}

#endif