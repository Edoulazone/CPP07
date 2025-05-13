/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:58:43 by eschmitz          #+#    #+#             */
/*   Updated: 2025/05/13 18:03:21 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(t &a, T &b) {
	T temp;
	
	temp = b;
	b = a;
	a = temp;
}

template <typename T>
T min(const T &a, const T &b) {
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T min(const T &a, const T &b) {
	if (a > b)
		return (a);
	return (b);
};