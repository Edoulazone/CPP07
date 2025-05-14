/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:29:12 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/14 14:35:33 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

template <typename T>
class Array {
	private:
		T 			*_elements;
		const int	_size;

	public:
		// Default Constructor
		Array();
		// Default destructor
		~Array();
		// Copy constructor
		Array(const Array &copy);
		// Constructor with unsigned int
		Array(unsigned int n);
		// = operator overload
		Array &operator=(const Array &copy);
		// [] operator overload
		T &operator[](unsigned int i);
		//Member functions
		unsigned int	size() const;
};

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