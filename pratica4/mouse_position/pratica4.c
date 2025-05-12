/*
Program: Mouse Position Tracker

Author: Joseph Alberto

Date: 18/04/2025

Description: This program tracks the mouse position and determines which quadrant of the screen it is in.

License: CC BY-SA
*/

// C code

#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main() {

    POINT cursor_pos;

    while (1) {
        
        char ch;

        if (GetCursorPos(&cursor_pos)) {

            // Print the cursor position
            printf("Mouse Position: x=%d, y=%d\n", cursor_pos.x, cursor_pos.y);

            int quadrant;

            // Check which quadrant the cursor is in
            if(cursor_pos.x < 1366/2 & cursor_pos.y < 768/2) {
                quadrant = 1;
            } 
            else if(cursor_pos.x > 1366/2 & cursor_pos.y < 768/2 ){
                quadrant = 2;
            } 
            else if(cursor_pos.x < 1366/2 & cursor_pos.y > 768/2 ){
                quadrant = 3;
            } 
            else {
                quadrant = 4;
            }

            // Print the quadrant with switch 
            switch(quadrant)
            {
            case 1:
                printf("Mouse is in A.\n");
                break;
            case 2:
                printf("Mouse is in B.\n");
                break;
            case 3:
                printf("Mouse is in C.\n");
                break;
            case 4:
                printf("Mouse is in D.\n");
                break;
            default:
                printf("Mouse is in unknown quadrant.\n");
                break;
            }
        }

        // Sleep for 500 milliseconds
        Sleep(500); 

        // Check for keyboard input
        if (kbhit()) {

            ch = getch();

            if (ch == 27)
                break;

        }
    }
    return 0;
}

