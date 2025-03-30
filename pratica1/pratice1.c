/*
Program: Calculating elements of circle and rectangle

Author: Joseph Alberto

Date: February, 28.

Description: This program calculates the circle length and area or the perimeter and area of a rectangle, based on user input.

License: CC BY-SA
*/

// C code

#include <stdio.h>
#include <stdlib.h>

// Declare the constant pi
const float pi = 3.14;

// Collection of undeclared circle variables
typedef struct{

    float radius;
    float length;
    float area;

}  circle;

// Collection of undeclared rectangle variables
typedef struct {

    float *side1;
    float *side2;
    float perimeter;
    float area;

} rectangle;

int main() {

    // Asks the user to choose the desired calculation
    printf("Choose the calculation you want.\n");
    printf("Enter 1 if you want to calculate circle elements.\n");
    printf("Enter 2 if you want to calculate rectangle elements.\n");

    // Declare the choice variable
    int choice;

    // Requests and storages the user choice
    printf("Enter a number: ");
    scanf("%d", &choice);

    // Calculation of circle elements based on user choice 
    if (choice == 1) {

        // Creating local circles variables 
        circle circ;

        // Requests and storages the radius of circle
        printf("Enter with radius of the circle: ");
        scanf("%f", &circ.radius);

        // Area and length calculation
        circ.area = pi * (circ.radius * circ.radius);
        circ.length = 2 * pi * circ.radius;

        // Show the result for the circle
        printf("The circle with radius %.2f has an area of %.2f and length of %.2f.", circ.radius, circ.area, circ.length);

    }

    // Calculation of rectangle elements based on user choice
    else if (choice == 2){

        // Creating local rectangles variables 
        rectangle rec;

        // Dynamic memory allocation for the sides
        rec.side1 = (float*) malloc(sizeof(float));
        rec.side2 = (float*) malloc(sizeof(float));

        // Requests and storages the sides of rectangle
        printf("Enter with sides of the rectangle <side 1, side 2>: ");
        scanf("%f, %f", rec.side1, rec.side2);

        // Evaluates whether the sides form a rectangle
        if (*rec.side1 != 0 && *rec.side2 != 0){

            // Area and perimeter calculation
            rec.area = (*rec.side1) * (*rec.side2);
            rec.perimeter = 2 * ((*rec.side1) + (*rec.side2));

            // Show the result for the rectangle
            printf("The rectangle with sides %.2f and %.2f has an area of %.2f and perimeter of %.2f.", *rec.side1, *rec.side2, rec.area, rec.perimeter);

            // Free the allocated memory
            free(rec.side1);
            free(rec.side2);
        }

        // If the sides are not valid, the program displays an error
        else {

            printf("The entered sides are not valid.");

        }

    }

    // If the user does not choose a valid option, the program displays an error
    else {

        printf("The number entered is not valid.");

    };

    return 0;

}
