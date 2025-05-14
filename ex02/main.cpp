/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:24:38 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/14 14:35:47 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

template <typename T>
void displayArray(const Array<T>& arr, const std::string& name) {
    std::cout << name << " (size " << arr.size() << "): ";
    try {
        for (unsigned int i = 0; i < arr.size(); i++) {
            // We need to const_cast here because the [] operator isn't const
            const Array<T>& constRef = arr;
            Array<T>& nonConstRef = const_cast<Array<T>&>(constRef);
            std::cout << nonConstRef[i];
            if (i < arr.size() - 1)
                std::cout << ", ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
}

void testEmptyArray() {
    std::cout << BLUE << "\n=== Testing Empty Array ===" << RESET << std::endl;
    
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    
    try {
        std::cout << "Trying to access element 0: ";
        std::cout << emptyArray[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
}

void testIntArray() {
    std::cout << BLUE << "\n=== Testing Int Array ===" << RESET << std::endl;
    
    Array<int> numbers(5);
    std::cout << "Default initialized array: ";
    displayArray(numbers, "numbers");
    
    // Modify elements
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
    }
    
    std::cout << "After modification: ";
    displayArray(numbers, "numbers");
    
    // Test out of bounds access
    try {
        std::cout << "Trying to access element at index 10: ";
        std::cout << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
    
    // Test copy constructor
    Array<int> numbersCopy(numbers);
    std::cout << "Copy of array: ";
    displayArray(numbersCopy, "numbersCopy");
    
    // Modify original to confirm deep copy
    numbers[2] = 999;
    std::cout << "Original after modification: ";
    displayArray(numbers, "numbers");
    std::cout << "Copy after original was modified: ";
    displayArray(numbersCopy, "numbersCopy");
}

void testStringArray() {
    std::cout << BLUE << "\n=== Testing String Array ===" << RESET << std::endl;
    
    Array<std::string> strings(3);
    
    strings[0] = "Hello";
    strings[1] = "42";
    strings[2] = "World";
    
    displayArray(strings, "strings");
    
    // Test assignment operator
    Array<std::string> stringsCopy;
    stringsCopy = strings;
    
    std::cout << "Copy via assignment: ";
    displayArray(stringsCopy, "stringsCopy");
    
    // Modify original to confirm deep copy
    strings[1] = "Changed!";
    std::cout << "Original after modification: ";
    displayArray(strings, "strings");
    std::cout << "Copy after original was modified: ";
    displayArray(stringsCopy, "stringsCopy");
}

void testZeroSizeArray() {
    std::cout << BLUE << "\n=== Testing Zero Size Array ===" << RESET << std::endl;
    
    Array<double> zeros(0);
    std::cout << "Zero size array size: " << zeros.size() << std::endl;
    
    try {
        std::cout << "Trying to access element 0: ";
        std::cout << zeros[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Error: " << e.what() << RESET << std::endl;
    }
}

void testAssignmentEdgeCases() {
    std::cout << BLUE << "\n=== Testing Assignment Edge Cases ===" << RESET << std::endl;
    
    // Create a reference array
    Array<int> arr1(3);
    for (unsigned int i = 0; i < arr1.size(); i++) {
        arr1[i] = i + 1;
    }
    
    std::cout << "Original array: ";
    displayArray(arr1, "arr1");
    
    // Create a copy for testing
    Array<int> arr2(arr1);
    
    std::cout << "Copy of original: ";
    displayArray(arr2, "arr2");
    
    // Assign larger array to smaller
    Array<int> smaller(2);
    smaller[0] = 100;
    smaller[1] = 200;
    
    std::cout << "Smaller array: ";
    displayArray(smaller, "smaller");
    
    smaller = arr1;
    
    std::cout << "After assigning larger array: ";
    displayArray(smaller, "smaller");
    
    // Assign smaller array to larger
    Array<int> bigger(5);
    for (unsigned int i = 0; i < bigger.size(); i++) {
        bigger[i] = i * 100;
    }
    
    std::cout << "Bigger array: ";
    displayArray(bigger, "bigger");
    
    bigger = smaller;
    
    std::cout << "After assigning smaller array: ";
    displayArray(bigger, "bigger");
}

int main() {
    std::cout << YELLOW << "===== ARRAY TEMPLATE CLASS TESTS =====" << RESET << std::endl;
    
    testEmptyArray();
    testIntArray();
    testStringArray();
    testZeroSizeArray();
    testAssignmentEdgeCases();
    
    std::cout << GREEN << "\nAll tests completed successfully!" << RESET << std::endl;
    
    return 0;
}