/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:40:04 by wweerasi          #+#    #+#             */
/*   Updated: 2026/03/22 20:06:00 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <climits>

#define SET_RED		"\033[31m"
#define RESET		"\033[0m"

class PmergeMe {
    private:
        std::vector<int>    _vecSeq;
        std::deque<int>     _deqSeq;
    
    public:
		PmergeMe() = default;
		PmergeMe(const PmergeMe& other) = default;
		PmergeMe& operator=(const PmergeMe& other) = default;
		~PmergeMe() = default;

        void parseSequence(char** intSeq);
        void mergeInsertSort();
};

#endif