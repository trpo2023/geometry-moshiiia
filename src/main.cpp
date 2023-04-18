#include "geometry/Circle.h"
#include <iomanip>
#include <iostream>

// Main function to test the input validator
int main()
{
    int n = 0;
    std::cout << "Input count of figures:";
    std:: cin >> n;
    Circle *arr = new Circle[n];
    
    std::cout << "Input params.\nExample:circle(10.0 2.0, 3)\n 0-Exit"
              << std::endl;
    
    for (int i=0; i < n; i++){
        std::cout << "Input params.\n" << std::endl;
        std::string input; 
        getline(std::cin, input);
        if (validateCircle(input, arr[i])) {
            std::cout << "Valid circle: area = " << std::setprecision(3)
                      << arr[i].area << ", perimeter = " << std::setprecision(3)
                      << arr[i].perimeter << "." << std::endl;
        } else {
            std::cout << "Invalid input" << std::endl;
        }
        std::cout << std::endl;
     }
    return 0;
}
