#include "circle.h"
#include <iomanip>
#include <iostream>

enum ERROR { 
 
};

// Main function to test the input validator
int main()
{
    int n = 0;
    std::cout << "Input count of figures:";
    std:: cin >> n;
    std::cin.ignore();
    Circle *arr = new Circle[n];
    std::cout << n;
    std::cout << "Input params.\nExample:circle(10.0 2.0, 3)\n 0-Exit" << std::endl;
    
    for (int i = 0; i < n; i++){
        std::cout << "Input params.\n" << std::endl;
        std::string input;
        getline(std::cin, input);

        switch (validateCircle(input, arr[i]))
        {
        case 1: std::cout << "Error at column " << ": expected 'circle'" << std::endl;
            break;
        case 2: std::cout << "Error at column " <<  ": ( or )" << std::endl;
            break;
        case 3: std::cout << "Error at column " <<  ": expected <double>" << std::endl;
            break;
        case 4: std::cout << "Error at column " << ": expected <double><double><double>"<< std::endl;
            break;
        case 5: std::cout << "Valid circle: area = " << std::setprecision(3)
                      << arr[i].area << ", perimeter = " << std::setprecision(3)
                      << arr[i].perimeter << "." << std::endl;
            break;
        }
        //std::cout << arr[i].validate; 
     }
    
    if (isIntersection(arr, n)){
        std::cout << "Intersection!\n";
    } else {
        std::cout << "No intersection!\n";
    }
    return 0;
}
