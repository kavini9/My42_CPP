/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:27:09 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/17 22:31:58 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int maxSize) : _maxSize(maxSize) {
	_intVec.reserve(maxSize);
}

void Span::addNumber(int num) {
	if (_intVec.size() >= _maxSize)
		throw::std::out_of_range("Span is full");
	_intVec.push_back(num);
}

unsigned int Span::shortestSpan() const {
	if (_intVec.size() <= 1)
		throw std::logic_error("Not enough elements");
	std::sort(_intVec.begin(), _intVec.end());
	unsigned int sSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 1; i < _intVec.size(); ++i) {
		unsigned int diff = static_cast<unsigned int> (static_cast<long>(_intVec[i]) - _intVec[i - 1]);
		sSpan = std::min(sSpan, diff);
	}
	return sSpan;
}

unsigned int Span::longestSpan() const {
	if (_intVec.size() <= 1)
		throw std::logic_error("Not enough elements");
	auto [minIt, maxIt] = std::minmax_element(_intVec.begin(), _intVec.end());
	unsigned int lSpan = static_cast<unsigned int> (static_cast<long>(*maxIt) - *minIt);
	return lSpan;
}