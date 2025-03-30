/*
Program: Calculating elements of circle and rectangle

Author: Joseph Alberto

Date: March, 04.

Description: This program calculates the circle length and area or the perimeter and area of a rectangle, based on user input.

License: CC BY-SA
*/

#include <iostream>

// Declare the constant pi
const float pi = 3.14;

// Collection of undeclared circle variables
struct circle{

    float radius;
    float length;
    float area;

};

// Collection of undeclared rectangle variables
struct rectangle{

    float * side1;
    float * side2;
    float perimeter;
    float area;

};

int main() {

    // Asks the user to choose the desired calculation
    std::cout << "Choose the calculation you want." << std::endl;
    std::cout << "Enter 1 if you want to calculate circle elements." << std::endl;
    std::cout << "Enter 2 if you want to calculate rectangle elements." << std::endl;

    // Declare the choice variable
    int choice;

    // Requests and storages the user choice
    std::cout << "Enter a number: ";
    std::cin >> choice;

    // Calculation of circle elements based on user choice 
    if (choice == 1) {

        // Creating local circles variables 
        circle circ;

        // Requests and storages the radius of circle
        std::cout << "Enter with radius of the circle: ";
        std::cin >> circ.radius;

        // Area and length calculation
        circ.area = pi * (circ.radius * circ.radius);
        circ.length = 2 * pi * circ.radius;

        // Show the result for the circle
        std::cout << "The circle with radius " << circ.radius << " has an area of " << circ.area << " and length of " << circ.length << "." << std::endl;

    }

    // Calculation of rectangle elements based on user choice
    else if (choice == 2){

        // Creating local rectangle variables 
        rectangle rec;

        // Dynamic memory allocation for the sides 
        rec.side1 = new float;
        rec.side2 = new float;

        // To capture the comma between values
        char comma;
        
        // Requests and storages the sides of rectangle
        std::cout << "Enter with sides of the rectangle <side 1, side 2>: ";
        std::cin >> *rec.side1 >> comma >> *rec.side2;

        // Evaluates the sides of the rectangle
        if (*rec.side1 == 0 || *rec.side2 == 0) {

            // If the user does not enter valid sides, the program displays an error
            std::cout << "The entered sides are not valid." << std::endl;

        }

        else{

            // Area and perimeter calculation
            rec.area = (*rec.side1) * (*rec.side2);
            rec.perimeter = 2 * ((*rec.side1) + (*rec.side2));

            // Show the result for the rectangle
            std::cout << "The rectangle with sides " << *rec.side1 << " and " << *rec.side2 << " has an area of " << rec.area << " and perimeter of " << rec.perimeter << "." << std::endl;

            // Free the allocated memory
            delete rec.side1;
            delete rec.side2;
        }
    }

    // If the user does not choose a valid option, the program displays an error
    else {

        std::cout << "The number entered is not valid." << std::endl;
    
    }

return 0;

};          