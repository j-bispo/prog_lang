/*
Program: File Access Parsing
Author: Joseph Alberto
Date: May 26, 2025
Description: 
License: CC BY
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream file("test_file.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    // Read and parse each line of the file
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        // Assuming each line in the file is CSV (Comma-Separated Values) format
        while (std::getline(ss, token, ',')) {
            // Process each token (field) in the line
            std::cout << token << std::endl;
        }
    }

    file.close();
    return 0;
}
