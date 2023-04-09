#include "Circle.h"

// Function to validate a circle object
bool validateCircle(const std::string& input, Circle& circle)
{
    std::smatch match;
    std::string figureExp = input.substr(0, 6);
    // std::cout<<input<<" ";
    // std::cout<<figureExp<<" ";
    if (!std::regex_match(figureExp, match, circle_regex)) {
        std::cout << "Error at column " << match.position()
                  << ": expected 'circle'" << std::endl;
        return false;
    }

    std::string symbolsExp = input.substr(6, input.length() - 6);
    // std::cout<<symbolsExp<<" ";
    if (!std::regex_match(symbolsExp, match, symbols)) {
        std::cout << "Error at column " << match.position() << ": ( or )"
                  << std::endl;
        return false;
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
            std::cout << "Error at column " << match.position()
                      << ": expected <double>" << std::endl;
            return false;
        }
    } else {
        std::cout << "Error at column " << match.position()
                  << ": expected <double><double><double>"
                     ""
                  << std::endl;
        return false;
    }
    return true;
}
