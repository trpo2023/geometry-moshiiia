#include <bits/stdc++.h>
#include <iostream>
#include <libgeometry/Circle.h>
#include <string.h>

int main()
{
    std::cout << "Input params.\nExample:circle(10.0 2.0, 3)\n 0-Exit"
              << std::endl;
    std::string input;
    while (input != "0") {
        std::cout << "Input params.\n" << std::endl;

        getline(std::cin, input);
        Circle circle;
        if (circle.validateObject(input, circle)) {
            // площадь и периметр
            // std::cout << "Valid circle: center=(" <<
            // std::setprecision(3)<<circle.center.x << "," <<
            // std::setprecision(3)<<circle.center.y << "), radius=" <<
            // std::setprecision(3)<<circle.radius << std::endl;
            std::cout << "Valid circle: area = " << std::setprecision(3)
                      << circle.area << ", perimeter = " << std::setprecision(3)
                      << circle.perimeter << "." << std::endl;
        } else {
            std::cout << "Invalid input" << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
