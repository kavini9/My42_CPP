/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:40:04 by wweerasi          #+#    #+#             */
/*   Updated: 2026/03/29 06:48:58 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <climits>
#include <chrono>
#include <iomanip>
#include <ranges>

#define SET_RED		"\033[31m"
#define SET_GRN		"\033[32m"
#define RESET		"\033[0m"

class PmergeMe {
	private:
		std::vector<int>    _intSeq;
		std::vector<int>    _jacobsthalSeq;
		
	public:
		PmergeMe() = default;
		PmergeMe(const PmergeMe& other) = default;
		PmergeMe& operator=(const PmergeMe& other) = default;
		~PmergeMe() = default;

		void run(char** rawSeq);
		void parseSequence(char** rawSeq);
		static void printElapsedTime(const std::string& contType, size_t contSize, double elapsedUs);
		void generateJacobsthal(int pendSize);
		
		template <typename Container>
		static void printSequence(const std::string& preText, const Container& seq) {
			std::cout << preText;
			for (size_t i = 0; i < seq.size(); ++i)
				std::cout << " " << seq[i];
			std::cout <<std::endl;
		}
		
		template <typename Container>
		void sortMergeInsert(Container& seq) {
			size_t seqSize = seq.size();
			if (seqSize < 2)
				return;
			int straggler = seqSize % 2 ? seq.back() : -1;
			if (straggler != -1) {
					seq.pop_back();
					--seqSize;			
			}
			std::vector<std::pair<int, int>> pairs;
			Container main;
			
			pairs.reserve(seqSize/2);
			for (size_t i = 0; i < seqSize; i += 2) {
				int a = seq[i];
				int b = seq[i + 1];
				if (a < b) std::swap(a, b);
				pairs.emplace_back(a,b);
				main.push_back(a);
			}
			sortMergeInsert(main);
			Container pend;
			for (int a : main) {
				for (std::pair<int, int>& p: pairs) {
					if (p.first == a) {
						pend.push_back(p.second);
						p.first = -1;
						break;
					}
				}
			}
			if (straggler != -1) 
				pend.push_back(straggler);
			int lastJacobJump = 0;
			if (!pend.empty())
				main.insert(main.begin(), pend[0]);
			if (!pend.empty())
				lastJacobJump = 1;

			for (int i = 1; i < static_cast<int>(_jacobsthalSeq.size()); ++i) {
				int maxId = std::min(_jacobsthalSeq[i], static_cast<int>(pend.size()));
				for (int j = maxId; j > lastJacobJump; --j) {
					int b = pend[j - 1];
					auto iter = std::lower_bound(main.begin(), main.end(), b);
					main.insert(iter, b);
				}
                if (maxId == static_cast<int>(pend.size()))
                    break;
				lastJacobJump = maxId;
			}
			seq = main;
		}
};

#endif