/*
Program: File Access Serial
Author: Joseph Alberto
Date: May 12, 2025
Description: This program opens a file and reads its contents character by character.
License: CC BY
*/

#include <iostream>

void read_characters(char filename[100]) {

    FILE *file;
    char character;

    // Open the file for reading
    file = fopen(filename, "r");
    // Check if the file was not null
    if (file == NULL) {
        std::cout << "Error opening the file." << std::endl;
        return; // Exit with error code
    }

    std::cout << "Reading characters:" << std::endl;
    // Read each character from the file serially and print it
    while ((character = fgetc(file)) != EOF) {
        // std::endl is included to show how much information is get each time
        std::cout << character << std::endl;
    }
    // Close the file 
    fclose(file); 
}

void read_lines(char filename[100]) {

    FILE *file; 
    char line[100];

    // Open the file for reading
    file = fopen(filename, "r");
    // Check if the file was not null
    if (file == NULL) {
        std::cout << "Error opening the file." << std::endl;
        return; // Exit the function if the file cannot be opened
    }

    std::cout << "\nReading lines:" << std::endl;
    while(fgets(line,sizeof(line), file) != NULL) {
        // Print the line read from the file
        std::cout << line << std::endl;
    }
    // Close the file
    fclose(file);
}

int main() {

    char filename[100] = "C:\\Users\\20241EN20144\\Documents\\prog_lang\\pratica8\\test_file.txt";
    
    read_characters(filename);
    read_lines(filename);

    return 0;
}
