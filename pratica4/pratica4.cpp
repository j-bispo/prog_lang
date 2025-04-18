/*
Program: Mouse Position Tracker

Author: Joseph Alberto

Date: April, 18

Description: This program tracks the mouse position on the screen and prints the coordinates and the quadrant in which the mouse is located.

License: CC BY-SA
*/

#include <iostream>
#include <windows.h>
#include <conio.h>

int main() {

    POINT cursor_pos;

    while (1) {

        char ch;
        
        // Get the current mouse position
        if (GetCursorPos(&cursor_pos)) {
            std::cout << "Mouse Position: x= " << cursor_pos.x << ", y= " << cursor_pos.y << std::endl;
        }

        // Print the current quadrant cursor position
        if(cursor_pos.x < 1366/2 & cursor_pos.y < 768/2) {
            std::cout << "Mouse is in A." << std::endl;
        } 
        else if(cursor_pos.x > 1366/2 & cursor_pos.y < 768/2 ){
            std::cout << "Mouse is in B." << std::endl;
        } 
        else if(cursor_pos.x < 1366/2 & cursor_pos.y > 768/2 ){
            std::cout << "Mouse is in C." << std::endl;
        } 
        else {
            std::cout << "Mouse is in D." << std::endl;
        }

        Sleep(500); 

        // Check if a key has been pressed
        if (kbhit()) {

            ch = getch();

            // Check if the key pressed is ESC to exit the loop
            if (ch == 27) 
                break;
       }
   }
return 0;
}