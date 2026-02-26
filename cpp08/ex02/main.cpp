/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:31:39 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/26 22:48:17 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

#define SET_B_YLW	"\033[1;33m"
#define SET_B_BLK	"\033[1;30m"
#define SET_RED		"\033[31m"
#define RESET		"\033[0m"

int main()
{
	{
		try
		{
			std::cout << SET_B_YLW "------------------ Subject main ------------------" RESET << std::endl;
			MutantStack<int> mstack;
			mstack.push(5);
			mstack.push(17);
			std::cout << mstack.top() << std::endl;
			mstack.pop();
			std::cout << mstack.size() << std::endl;
			mstack.push(3);
			mstack.push(5);
			mstack.push(737);
			mstack.push(0);
			MutantStack<int>::iterator it = mstack.begin();
			MutantStack<int>::iterator ite = mstack.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
			std::stack<int> s(mstack);
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		try
		{
			std::cout << SET_B_YLW "------------------ Subject main for List ------------------" RESET << std::endl;
			std::list<int> mstack;
			mstack.push_back(5);
			mstack.push_back(17);
			std::cout << mstack.back() << std::endl;
			mstack.pop_back();
			std::cout << mstack.size() << std::endl;
			mstack.push_back(3);
			mstack.push_back(5);
			mstack.push_back(737);
			mstack.push_back(0);
			std::list<int>::iterator it = mstack.begin();
			std::list<int>::iterator ite = mstack.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
			std::list<int> s(mstack);
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		std::cout << std::endl;
		try {
			std::cout << SET_B_YLW "------------------ Iterator Semantics & Const Correctness ------------------" RESET << std::endl;
			MutantStack<int> mstack;
			for (int i = 0; i < 10 ; i++) {
				mstack.push(i * 5);
			}

			std::cout << SET_B_BLK "Forward iteration (iterator):" RESET << std::endl;
			for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
				std::cout << *it << " ";
			}
			std::cout << std::endl << std::endl;
			std::cout << SET_B_BLK "Reverse iteration (reverse iterator):" RESET << std::endl;
			for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
				std::cout << *rit << " ";
			}
			std::cout << std::endl << std::endl;	

			std::cout << SET_B_BLK "Modification test : MutantStack<int>::iterator it = mstack.begin()" RESET << std::endl;
			MutantStack<int>::iterator it = mstack.begin();
			std::cout << "*it += 100: " << ((*it) += 100) << std::endl;
			std::cout << "*it -= 100: " << ((*it) -= 100);
			std::cout << std::endl << std::endl;

			const MutantStack<int> cstack = mstack;
			
			std::cout << SET_B_BLK "Const forward iteration (const iterator):" RESET << std::endl;
			for (MutantStack<int>::const_iterator cit = cstack.begin(); cit != cstack.end(); ++cit) {
				std::cout << *cit << " ";
			}
			std::cout << std::endl << std::endl;
			std::cout << SET_B_BLK "Const reverse iteration (const reverse iterator):" RESET << std::endl;
			for (MutantStack<int>::const_reverse_iterator crit = cstack.rbegin(); crit != cstack.rend(); ++crit) {
				std::cout << *crit << " ";
			}
			std::cout << std::endl << std::endl;
			std::cout << SET_B_BLK "Modification test : MutantStack<int>::const_iterator cit = cstack.begin()" RESET << std::endl;
			// MutantStack<int>::const_iterator cit = cstack.begin();
			// std::cout << "*cit + 100:" << ((*cit) += 100);
			// std::cout << "*cit -= 100: " << ((*cit) -= 100);
			// std::cout << std::endl;
			std::cout << std::endl;
			
			std::cout << SET_B_BLK "Explicit const forward iteration (cbegin/cend):" RESET << std::endl;
			for (MutantStack<int>::const_iterator ecit = mstack.begin(); ecit != mstack.end(); ++ecit) {
				std::cout << *ecit << " ";
			}
			std::cout << std::endl << std::endl;
			std::cout << SET_B_BLK "Explicit const reverse iteration (crbegin/crend):" RESET << std::endl;
			for (MutantStack<int>::const_reverse_iterator ecrit = mstack.rbegin(); ecrit != mstack.rend(); ++ecrit) {
				std::cout << *ecrit << " ";
			}
			std::cout << std::endl << std::endl;
			std::cout << SET_B_BLK "Modification test : MutantStack<int>::const_iterator ecit = mstack.begin()" RESET << std::endl;
			// MutantStack<int>::const_iterator ecit = mstack.begin();
			// std::cout << "*ecit + 100:" << ((*ecit) += 100);
			// std::cout << "*ecit -= 100: " << ((*ecit) -= 100);
			// std::cout << std::endl;
			std::cout << std::endl;
			
		}
		catch(const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	{
		try {
			std::cout << SET_B_YLW "------------------ Underlying Container Variation ------------------" RESET << std::endl;
			MutantStack<int> deqStack;						// uses deque
			MutantStack<int, std::vector<int>> vecStack;	// uses vector
			MutantStack<int, std::list<int>> lstStack;		// uses list
			
			for (int i = 0; i < 10 ; i++) {
				deqStack.push(i * 5);
				vecStack.push(i * 10);
				lstStack.push(i * 25);
			}
			std::cout << SET_B_BLK "Iterationg through => MutantStack<int> deqStack" RESET << std::endl;
			for (MutantStack<int>::iterator dit = deqStack.begin(); dit != deqStack.end(); ++dit) {
				std::cout << *dit << " ";
			}
			std::cout << std::endl << std::endl;
			std::cout << SET_B_BLK "Iterationg through => MutantStack<int, std::vector<int>> vecStack" RESET << std::endl;
			for (MutantStack<int, std::vector<int>>::iterator vit = vecStack.begin(); vit != vecStack.end(); ++vit) {
				std::cout << *vit << " ";
			}
			std::cout << std::endl << std::endl;
			std::cout << SET_B_BLK "Iterationg through => MutantStack<int, std::list<int>> lstStack" RESET << std::endl;
			for (MutantStack<int, std::list<int>>::iterator lit = lstStack.begin(); lit != lstStack.end(); ++lit) {
				std::cout << *lit << " ";
			}
			std::cout << std::endl << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << SET_RED "Error: " << e.what() << RESET << std::endl;
		}
	}
	
	return 0;
}