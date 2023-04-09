#include <regex>
#include <string.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include "geometry/Circle.h"


// Main function to test the input validator
int main()
{
    std::cout << "Input params.\nExample:circle(10.0 2.0, 3)\n 0-Exit" << std::endl;
    std::string input;
     while (input != "0")
     {
        std::cout << "Input params.\n" << std::endl;
        getline(std::cin,input);
        Circle circle;
        if (validateCircle(input, circle))
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
