#include "Circle.h"
#include <iostream>
#include <vector>
#include <cmath>

// Function to validate a circle object
int validateCircle(const std::string& input, Circle& circle)
{
    std::smatch match;
    std::string figureExp = input.substr(0, 6);
    // std::cout<<input<<" ";
    // std::cout<<figureExp<<" ";
    if (!std::regex_match(figureExp, match, circle_regex)) {
        //std::cout << "Error at column " << match.position() << ": expected 'circle'" << std::endl;
        circle.validate = 0;
        return 1;
    }

    std::string symbolsExp = input.substr(6, input.length() - 6);
    // std::cout<<symbolsExp<<" ";
    if (!std::regex_match(symbolsExp, match, symbols)) {
        //std::cout << "Error at column " << match.position() << ": ( or )" << std::endl;
        circle.validate = 0;
        return 2;
    }

    std::string numExp = input.substr(
            7, input.length() - 8); // какого последняя скобка не убирается
    // std::cout<<numExp<<" ";
    if (std::regex_match(numExp, match, circle_regex_num)) {
        try {
            circle.center.x = std::stod(match[1].str());
            circle.center.y = std::stod(match[2].str());
            circle.radius = std::stod(match[3].str());
            circle.area = 3.14 * circle.radius * circle.radius;
            circle.perimeter = 2 * 3.14 * circle.radius;
        } catch (const std::invalid_argument&) {
            //std::cout << "Error at column " << match.position()<< ": expected <double>" << std::endl;
            circle.validate = 0;
            return 3;
        }
    } else {
        //std::cout << "Error at column " << match.position() << ": expected <double><double><double>"<< std::endl;
        circle.validate = 0;
        return 4;
    }
    circle.validate = 1;
    return 5;
}

bool isIntersection(Circle arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 1; j < size - 1; j++){
            if(arr[i].validate != 0 && arr[j].validate != 0){
                if(abs(arr[i].center.x + arr[j].center.x) <= arr[i].radius + arr[j].radius) return true;
                if(abs(arr[i].center.y + arr[j].center.y) <= arr[i].radius + arr[j].radius) return true;
            }
        }
    }
    return false;
}
