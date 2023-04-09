#ifndef CIRCLE_H
#define CIRCLE_H
#include <libgeometry/Point.h>
#include <libgeometry/Object.h>
#include <regex>
#include <string.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

class Circle : Object {
public:
    Point center;
    double radius;
    double area;
    double perimeter;

    bool validateObject(const std::string &input, Circle &circle) override;
};

#endif
