#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort
#include <iterator> // Required for std::find

int main() {
    std::vector<int> vector = {20, 10, 50, 40, 30};

    // Direct access by index
    std::cout << "Direct access by index:" << std::endl;
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << "Element " << i << ": " << vector[i] << std::endl;
    }
    std::cout << std::endl;

    // Sorting the vector
    std::sort(vector.begin(), vector.end());

    // Display sorted vector
    std::cout << "Sorted vector:" << std::endl;
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << "Element " << i << ": " << vector[i] << std::endl;
    }
    std::cout << std::endl;

    // Finding an element
    int element_to_find = 30;
    auto it = std::find(vector.begin(), vector.end(), element_to_find);
    if (it != vector.end()) {
        std::cout << "Element " << element_to_find << " found at position: " \
                  << std::distance(vector.begin(), it) << std::endl;
    } else {
        std::cout << "Element " << element_to_find << " not found." << std::endl;
    }

    return 0;
}