/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:39:59 by wweerasi          #+#    #+#             */
/*   Updated: 2026/03/29 05:14:26 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

using Clock = std::chrono::high_resolution_clock;
using Duration = std::chrono::duration<double, std::micro>;

void PmergeMe::parseSequence(char** rawSeq) {
	for (int i = 0; rawSeq[i] != nullptr; ++i) {
		char* pEnd = nullptr;
		long num = strtol(rawSeq[i], &pEnd, 10);
		if (pEnd && *pEnd != '\0')
			throw std::runtime_error("non-numeric character found.");
		if (num <= 0)
			throw std::runtime_error("non-positive integer found.");
		if (num > INT_MAX)    
			throw std::runtime_error("integer overflow.");
		_intSeq.push_back(static_cast<int>(num));
	}
}

void PmergeMe::printElapsedTime(const std::string& contType, size_t contSize, double elapsedUs) {
	std::cout << "Time to process a range of " << contSize << " elements with " << contType
		<< " : " << std::fixed << std::setprecision(5) << elapsedUs << " us" << std::endl;
}

void PmergeMe::run(char** rawSeq) {
	parseSequence(rawSeq);
	printSequence("Before:", _intSeq);

	const Clock::time_point vecStart = Clock::now();
	generateJacobsthal(_intSeq.size());
	std::vector<int> vecSeq(_intSeq);
	sortMergeInsert(vecSeq);
	const Clock::time_point vecEnd = Clock::now();

	const Clock::time_point deqStart = Clock::now();
	generateJacobsthal(_intSeq.size());
	std::deque<int> deqSeq(_intSeq.begin(), _intSeq.end());
	sortMergeInsert(deqSeq);
	const Clock::time_point deqEnd = Clock::now();

	printSequence("After:", vecSeq);
	printElapsedTime("std::vector", vecSeq.size(), Duration(vecEnd - vecStart).count());
	printElapsedTime("std::deque", deqSeq.size(), Duration(deqEnd - deqStart).count());
}

void PmergeMe::generateJacobsthal(int pendSize) {
    if (pendSize <= 0) 
		_jacobsthalSeq = {};
    else if (pendSize == 1) 
		_jacobsthalSeq = {1};
	else
    	_jacobsthalSeq = {1, 3}; 
    
    while (_jacobsthalSeq.back() < pendSize) {
        int next = _jacobsthalSeq.back() + 2 * _jacobsthalSeq[_jacobsthalSeq.size() - 2];
        _jacobsthalSeq.push_back(next);
    }
}