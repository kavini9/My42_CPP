/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:59 by wweerasi          #+#    #+#             */
/*   Updated: 2026/03/22 20:06:27 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::parseSequence(char** intSeq) {
	for (int i = 0; intSeq[i] != nullptr; ++i) {
		char* pEnd = nullptr;
		long num = strtol(*intSeq, &pEnd, 10);
		if (pEnd && *pEnd != '\0')
			throw std::runtime_error("non-numeric character found.");
		if (num <= 0)
			throw std::runtime_error("non-positive integer found.");
		if (num > INT_MAX)    
			throw std::runtime_error("integer overflow.");
		_vecSeq.push_back(static_cast<int>(num));
		_deqSeq.push_back(static_cast<int>(num));
	}
}

void PmergeMe::mergeInsertSort() {
	
}