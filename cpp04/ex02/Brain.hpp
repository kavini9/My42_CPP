/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 22:38:15 by wweerasi          #+#    #+#             */
/*   Updated: 2025/10/13 21:33:14 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	private:
		std::string _ideas[100];
	
	public:
		Brain();
		Brain(const Brain& other);
		Brain&   operator=(const Brain& other);
		~Brain();

		void setIdea(int idx, std::string idea);
		std::string getIdea(int idx) const;
};

#endif