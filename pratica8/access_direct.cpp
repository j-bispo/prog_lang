/*
Program: File Access Directly
Author: Joseph Alberto
Date: May 12, 2025
Description: 
License: CC BY
*/

#include <stdio.h>
#include <stdlib.h>  // To use the exit() function
#include <string.h>  // To use the strlen() function

// Definition of the "data" structure to represent dates
struct data {
    int d, m, a;  // Day, month, year
};

int main() {
    struct data d1 = {7, 9, 1999};  // Initialization of the first date
    struct data d2 = {12, 5, 2024};  // Initialization of the second date
    
    struct data e1;  // Declaration of another date for reading from the file
    struct data e2;  // Declaration of another date for reading from the file

    FILE *file;  // File pointer
    char filename[30];  // String to store the file name
    
    // Asks the user for the file name
    printf("Enter filename:");
    fgets(filename, 30, stdin);  // Reads user input securely
    filename[strlen(filename) - 1] = '\0';  // Removes the newline character
    
    // Opens the file for binary writing
    if (!(file = fopen(filename, "wb"))) {
        printf("Error! Unable to open file for writing!\n");
        exit(1);  // Exits the program in case of error
    }
    fwrite(&d1, sizeof(struct data), 1, file);  // Writes the first structure to the file
    fwrite(&d2, sizeof(struct data), 1, file);  // Writes the second structure to the file
    fclose(file);  // Closes the file

    // Opens the file for binary reading
    if (!(file = fopen(filename, "rb"))) {
        printf("Error! Unable to open file for reading!\n");
        exit(1);  // Exits the program in case of error
    }
    fread(&e1, sizeof(struct data), 1, file);  // Reads the first structure from the file
    fread(&e2, sizeof(struct data), 1, file);  // Reads the second structure from the file
    fclose(file);  // Closes the file

    // Displays the dates read from the file
    printf("First Date: %d/%d/%d\n", e1.a, e1.m, e1.d);
    printf("Second Date: %d/%d/%d\n", e2.a, e2.m, e2.d);

    return 0;  // Indicates that the program executed successfully
}