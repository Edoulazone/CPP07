/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:36:46 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/14 10:58:07 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _elements(NULL), _size(0) {
}

template <typename T>
Array<T>::~Array() {
	delete[] _elements;
}

template <typename T>
Array<T>::Array(const Array &copy): _size(copy._size) {
	_elements = new T[_size];
	for (int i = 0; i < _size; i++) {
		_elements[i] = copy._elements[i];
	}
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n) {
	_elements = new T[n];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy) {
	delete[] _elements;
	_size = copy._size;
	_elements = new T[_size];
	for (int i = 0; i < _size; i++) {
		_elements[i] = copy._elements[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
	if (i >= _size)
		throw std::out_of_range("Index out of range");
	return _elements[i];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}