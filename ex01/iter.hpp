/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:21:08 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/14 10:26:55 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
T iter(const T &array, int len, void (*fn)(T &)) {
	for (int i = 0; i < len; i++) {
		fn(array[i]);
	}
}