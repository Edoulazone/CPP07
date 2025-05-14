/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:58:40 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/14 14:46:43 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

int main() {
    int a = 10, b = 20;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;

    float x = 1.5f, y = 3.7f;
    std::cout << "\nBefore swap: x = " << x << ", y = " << y << std::endl;
    swap(x, y);
    std::cout << "After swap:  x = " << x << ", y = " << y << std::endl;

    std::string s1 = "Hello", s2 = "World";
    std::cout << "\nBefore swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    swap(s1, s2);
    std::cout << "After swap:  s1 = " << s1 << ", s2 = " << s2 << std::endl;

    return 0;
}