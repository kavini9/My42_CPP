/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:27:19 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/17 22:13:55 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
	private:
		unsigned int _maxSize = 0;
		mutable std::vector<int> _intVec;

	public:
		Span() = default;
		explicit Span(unsigned int maxSize);
		Span(const Span& other) = default;
		Span& operator=(const Span& other) = default;
		~Span() = default;

		void addNumber(int num);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		template <typename InputIt>
		void addRange(InputIt first, InputIt last) {
			if (std::distance(first, last) + _intVec.size() > _maxSize)
				throw std::out_of_range("No enough space in Span")
			_intVec.insert(_intVec.end(), first, last);
		}
};

#endif
