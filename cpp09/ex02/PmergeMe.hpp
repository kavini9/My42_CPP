/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:40:04 by wweerasi          #+#    #+#             */
/*   Updated: 2026/03/24 21:30:02 by wweerasi         ###   ########.fr       */
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
        
        template <typename Container>
        void mergeInsertionSort(Container& arr) {
        if (arr.size() < 2) return;
        bool hasStraggler = (arr.size() % 2 != 0);
        int straggler = 0; 
        if (hasStraggler) {
            straggler = arr.back();
            arr.pop_back();
        }
        std::vector<std::pair<int, int>> pairs;
        Container winners;

        pairs.reserve(arr.size() / 2);
        for (size_t i = 0; i < arr.size(); i += 2) {
            int a = arr[i];
            int b = arr[i + 1];
            if (a < b) std::swap(a, b); 
            
            pairs.emplace_back(a, b);
            winners.push_back(a);
        }
        mergeInsertionSort(winners);
        Container pend;
        for (int w : winners) {
            for (auto& p : pairs) {
                if (p.first == w) {
                    pend.push_back(p.second);
                    p.first = -1;
                    break;
                }
            }
        }
        if (hasStraggler) pend.push_back(straggler);
        Container mainChain = winners;
        mainChain.insert(mainChain.begin(), pend[0]);
        auto jacob = generateJacobsthal(pend.size());
        int lastInsertedIdx = 0;

        for (size_t i = 1; i < jacob.size(); ++i) {
            int maxIdx = std::min(jacob[i], static_cast<int>(pend.size()));

            for (int j = maxIdx; j > lastInsertedIdx; --j) {
                int loserToInsert = pend[j - 1];
                auto it = std::ranges::lower_bound(mainChain, loserToInsert);
                mainChain.insert(it, loserToInsert);
            }
            lastInsertedIdx = maxIdx;
        }
        arr = mainChain;
        }
};

#endif