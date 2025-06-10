/*
Program: File Access Directly
Author: Joseph Alberto
Date: May 12, 2025
Description: 
License: CC BY
*/

#include <iostream>
#include <fstream>
#include <string>

// Definition of the "Data" structure to represent dates
struct Data {
    int d, m, a;  // Day, month, year
};

int main() {
    Data d1 = {7, 9, 1999};   // Initialization of the first date
    Data d2 = {12, 5, 2024};  // Initialization of the second date

    Data e1;  // Declaration of another date for reading from the file
    Data e2;  // Declaration of another date for reading from the file

    std::string filename;
    std::cout << "Enter filename: ";
    std::getline(std::cin, filename);

    // Opens the file for binary writing
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        std::cerr << "Error! Unable to open file for writing!" << std::endl;
        return 1;
    }
    ofs.write(reinterpret_cast<char*>(&d1), sizeof(Data));
    ofs.write(reinterpret_cast<char*>(&d2), sizeof(Data));
    ofs.close();

    // Opens the file for binary reading
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        std::cerr << "Error! Unable to open file for reading!" << std::endl;
        return 1;
    }
    ifs.read(reinterpret_cast<char*>(&e1), sizeof(Data));
    ifs.read(reinterpret_cast<char*>(&e2), sizeof(Data));
    ifs.close();

    // Displays the dates read from the file
    std::cout << "First Date: " << e1.a << "/" << e1.m << "/" << e1.d << std::endl;
    std::cout << "Second Date: " << e2.a << "/" << e2.m << "/" << e2.d << std::endl;

    return 0;
}
