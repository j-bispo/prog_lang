#include <stdio.h>
#include <stdlib.h> // Required for malloc

int main() {
    // Allocate memory for an array of 5 elements
    int size = 5;
    int *ptr = (int *)malloc(size * sizeof(int));

    // Initialize the elements of the array
    for (int i = 0; i < size; i++) {
        ptr[i] = (i + 1) * 10; // Example initialization: 10, 20, 30, 40, 50
    }

    // Alternative access using pointer
    int *ptr_aux = ptr;
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i, *ptr_aux);
        ptr_aux++;
    }

    // Free the allocated memory
    free(ptr);

    return 0;
}