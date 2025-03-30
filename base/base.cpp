/*
Program: 

Author: Jose Alberto

Date: 

Description: 

License: CC BY-SA
*/

#include <iostream>

void swap(int &a, int &b) {
    
    int temp = a;
    a = b;
    b = temp;

}  

int main() {

    int x = 1;
    int y = 5;

    printf("%d\n", x);
    printf("%d\n", y);
    swap(x, y);
    printf("%d\n", x);
    printf("%d\n", y);

    return 0;

}