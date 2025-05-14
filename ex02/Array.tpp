/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:36:46 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/14 14:37:19 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include "Array.hpp"

// Default Constructor
template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

// Constructor with unsigned int
template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

// Destructor
template <typename T>
Array<T>::~Array() {
    if (_elements)
        delete[] _elements;
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array &copy) : _elements(NULL), _size(copy._size) {
    if (_size > 0) {
        _elements = new T[_size]();
        for (int i = 0; i < _size; i++)
            _elements[i] = copy._elements[i];
    }
}

// = operator overload
template <typename T>
Array<T> &Array<T>::operator=(const Array &copy) {
    if (this != &copy) {
        if (_elements)
            delete[] _elements;
        
        _elements = NULL;
        const_cast<int&>(_size) = copy._size;
        
        if (_size > 0) {
            _elements = new T[_size]();
            for (int i = 0; i < _size; i++)
                _elements[i] = copy._elements[i];
        }
    }
    return *this;
}

// [] operator overload
template <typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= static_cast<unsigned int>(_size))
        throw std::out_of_range("Index out of bounds");
    return _elements[i];
}

// Member function size
template <typename T>
unsigned int Array<T>::size() const {
    return static_cast<unsigned int>(_size);
}