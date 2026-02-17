/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:27:19 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/13 22:59:25 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
	private:
		unsigned int _maxSize = 0;
		std::vector<int> _intList;

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
		void addNumber(InputIt first, InputIt last) {
			
		}
};

#endif
