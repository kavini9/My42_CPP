/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:06:31 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/01 20:14:48 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array {
	private:
		T*      _data;
		size_t  _size;
		
	public:
		Array();
		Array(unsigned int size);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		unsigned int size() const;
};

#include "Array.tpp"

#endif