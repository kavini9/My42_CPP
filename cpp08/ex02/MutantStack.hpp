/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:31:45 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/24 21:30:08 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template< class T, class Container = typename std::stack<T>::container_type>
class MutantStack: public std::stack<T, Container> {
	public:
		MutantStack() = default;
		MutantStack(const MutantStack& other) = default;
		MutantStack& operator=(const MutantStack& other) = default;
		~MutantStack() = default;

		using iterator = typename Container::iterator;
		using const_iterator = typename Container::const_iterator;
		using reverse_iterator = typename Container::reverse_iterator;
		using const_reverse_iterator = typename Container::const_reverse_iterator;

		iterator	begin() { return this->c.begin(); }
		iterator	end(){ return this->c.end(); }
		reverse_iterator	rbegin() { return this->c.rbegin(); }
		reverse_iterator	rend() { return this->c.rend(); }
		
		const_iterator	begin() const { return this->c.begin(); }
		const_iterator	end() const { return this->c.end(); }
		const_reverse_iterator	rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator	rend() const { return this->c.rend(); }
		
		const_iterator	cbegin() const noexcept { return this->c.cbegin(); }
		const_iterator	cend() const noexcept { return this->c.cend(); }
		const_reverse_iterator	crbegin() const noexcept { return this->c.crbegin(); }
		const_reverse_iterator	crend() const noexcept { return this->c.crend(); }
};

#endif