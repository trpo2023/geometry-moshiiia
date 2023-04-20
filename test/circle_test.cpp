#ifndef CIRCLE_TEST
#define CIRCLE_TEST

#include "circle.h"
#include <gtest/gtest.h>
#include <string>

TEST(CIRCLE, isIntersection)
{
    Circle arrTrue[2];

    arrTrue[0].center.x = 10;
    arrTrue[0].center.y = 10;
    arrTrue[0].radius = 10;
    arrTrue[1].center.x = 10;
    arrTrue[1].center.y = 9;
    arrTrue[1].radius = 8;

    Circle arrFalse[2];
    arrFalse[0].center.x = 10;
    arrFalse[0].center.y = 10;
    arrFalse[0].radius = 5;
    arrFalse[1].center.x = 30;
    arrFalse[1].center.y = 30;
    arrFalse[1].radius = 3;

    bool a = isIntersection(arrTrue, 2);
    ASSERT_TRUE(a);

    bool b = isIntersection(arrFalse, 2);
    ASSERT_FALSE(b);
}

TEST(CIRCLE, validateCircle)
{
    Circle circle1;
    Circle circle2;
    Circle circle3;
    Circle circle4;
    std::string examp1 = "circle(10.4 10,10)";
    std::string examp2 = "crcle(10.3 10.6,10)";
    std::string examp3 = "circle(10 10,10";
    std::string examp4 = "circle(10 aa,10)";

    int a = validateCircle(examp1, circle1);
    ASSERT_EQ(a, 5);

    a = validateCircle(examp2, circle2);
    ASSERT_EQ(a, 1);

    a = validateCircle(examp3, circle3);
    ASSERT_EQ(a, 2);

    a = validateCircle(examp4, circle4);
    ASSERT_EQ(a, 4);
}

#endif