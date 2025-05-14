/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:39:18 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/14 14:39:55 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

// Function to print an integer
void printInt(int &n) {
    std::cout << n << " ";
}

// Function to double an integer
void doubleInt(int &n) {
    n *= 2;
}

// Function to uppercase a character
void toUpper(char &c) {
    c = std::toupper(c);
}

// Function to add exclamation mark to a string
void addExclamation(std::string &s) {
    s += "!";
}

int main() {
    // Test with integer array
    int intArray[] = {1, 2, 3, 4, 5};
    int intLen = 5;
    
    std::cout << "Original integers: ";
    iter(intArray, intLen, printInt);
    std::cout << std::endl;
    
    iter(intArray, intLen, doubleInt);
    
    std::cout << "After doubling: ";
    iter(intArray, intLen, printInt);
    std::cout << std::endl;
    
    // Test with character array
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    int charLen = 5;
    
    std::cout << "Original characters: ";
    for (int i = 0; i < charLen; i++) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;
    
    iter(charArray, charLen, toUpper);
    
    std::cout << "After uppercase: ";
    for (int i = 0; i < charLen; i++) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Test with string array
    std::string strArray[] = {"hello", "world", "cpp", "template"};
    int strLen = 4;
    
    std::cout << "Original strings: ";
    for (int i = 0; i < strLen; i++) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;
    
    iter(strArray, strLen, addExclamation);
    
    std::cout << "After adding exclamation: ";
    for (int i = 0; i < strLen; i++) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
