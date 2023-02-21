#include <regex>
#include <string.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

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

// Triangle structure
struct Triangle
{
    Point p1;
    Point p2;
    Point p3;
};

// Polygon structure
struct Polygon
{
    std::vector<Point> vertices;
};

// Regular expressions for each object type
const std::regex symbols("\\(.*\\)$");
const std::regex circle_regex("circle");
const std::regex circle_regex_num("\\s*(\\d+\\.?\\d*).\\s*(\\d+\\.?\\d*),\\s*(\\d+\\.?\\d*)$");

const std::regex triangle_regex("^triangle\\(((\\d+\\.?\\d*),\\s*(\\d+\\.?\\d*)),\\s*((\\d+\\.?\\d*),\\s*(\\d+\\.?\\d*)),\\s*((\\d+\\.?\\d*),\\s*(\\d+\\.?\\d*))\\)$");
const std::regex polygon_regex("^polygon\\(((\\d+\\.?\\d*),\\s*(\\d+\\.?\\d*)),\\s*((\\d+\\.?\\d*),\\s*(\\d+\\.?\\d*)),\\s*((\\d+\\.?\\d*),\\s*(\\d+\\.?\\d*))(,\\s*((\\d+\\.?\\d*),\\s*(\\d+\\.?\\d*)))*\\)$");

// Function to validate a circle object
bool validateCircle(const std::string &input, Circle &circle)
{
    std::smatch match;
    std::string figureExp = input.substr(0, 6);
    //std::cout<<figureExp<<" ";
    if (!std::regex_match(figureExp, match, circle_regex))
    {
        std::cout << "Error at column " << match.position() << ": expected 'circle'" << std::endl;
        return false;
    }

    std::string symbolsExp = input.substr(6,input.length()-6);
    //std::cout<<symbolsExp<<" ";
    if (!std::regex_match(symbolsExp, match, symbols))
    { 
        std::cout << "Error at column " << match.position() << ": ( or )" << std::endl;
        return false;
    }

    std::string numExp = input.substr(7, input.length()-8); //какого последняя скобка не убирается
    //std::cout<<numExp<<" ";
    if (std::regex_match(numExp, match, circle_regex_num))
    {
        try
        {
            circle.center.x = std::stod(match[1].str());
            circle.center.y = std::stod(match[2].str());
            circle.radius = std::stod(match[3].str());
            circle.area = 3.14*circle.radius*circle.radius;
            circle.perimeter = 2*3.14*circle.radius;
        }
        catch (const std::invalid_argument &)
        {
            std::cout << "Error at column " << match.position() << ": expected <double>" << std::endl;
            return false;
        }
    } else {
        std::cout << "Error at column " << match.position() << ": expected <double><double><double>""" << std::endl;
        return false;
    }
    return true;
}

// Function to validate a triangle object
bool validateTriangle(const std::string &input, Triangle &triangle)
{
    std::smatch match;
    if (!std::regex_match(input, match, triangle_regex))
    {
        return false;
    }
    triangle.p1.x = std::stod(match[2].str());
    triangle.p1.y = std::stod(match[3].str());
    triangle.p2.x = std::stod(match[5].str());
    triangle.p2.y = std::stod(match[6].str());
    triangle.p3.x = std::stod(match[8].str());
    triangle.p3.y = std::stod(match[9].str());
    return true;
}

// Function to validate a polygon object
bool validatePolygon(const std::string &input, Polygon &polygon)
{
    std::smatch match;
    if (!std::regex_match(input, match, polygon_regex))
    {
        return false;
    }
    for (size_t i = 2; i < match.size(); i += 2)
    {
        Point point;
        point.x = std::stod(match[i].str());
        point.y = std::stod(match[i + 1].str());
        polygon.vertices.push_back(point);
    }
    return true;
}

// Function to validate an object of any type
bool validateObject(const std::string &input, Circle &circle)
{
    return validateCircle(input, circle);
}

bool validateObject(const std::string &input, Triangle &triangle)
{
    return validateTriangle(input, triangle);
}

bool validateObject(const std::string &input, Polygon &polygon)
{
    return validatePolygon(input, polygon);
}

// Main function to test the input validator
int main()
{
    std::cout << "Input params.\nExample:circle(10.0, 2.0, 3)\n 0-Exit" << std::endl;
    std::string input;
     while (input != "0")
     {
        std::cout << "Input params.\n" << std::endl;
        std::cin >> input;
        Circle circle;
        if (validateObject(input, circle))
        {
            //площадь и периметр
            //std::cout << "Valid circle: center=(" << std::setprecision(3)<<circle.center.x << "," << std::setprecision(3)<<circle.center.y << "), radius=" << std::setprecision(3)<<circle.radius << std::endl;
            std::cout << "Valid circle: area = "<< std::setprecision(3)<<circle.area << ", perimeter = " << std::setprecision(3)<<circle.perimeter << "." << std::endl;
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
        }
        std::cout<<std::endl;
     }
    return 0;
}
