#ifndef CIRCLE
#define CIRCLE
#include <iostream>

// Point structure
struct Point
{
    double x;
    double y;
};

// Circle structure
struct Circle
{
    Point center;
    double radius;
    double area;
    double perimeter;
};


// Regular expressions for each object type
const std::regex symbols("\\(.*\\)$");
const std::regex circle_regex("circle$");
const std::regex circle_regex_num("\\s*(\\d+\\.?\\d*).\\s*(\\d+\\.?\\d*),\\s*(\\d+\\.?\\d*)$");

bool validateCircle(const std::string &input, Circle &circle);

#endif