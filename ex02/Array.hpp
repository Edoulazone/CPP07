/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:29:12 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/14 10:57:05 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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