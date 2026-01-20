/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:57:04 by wweerasi          #+#    #+#             */
/*   Updated: 2026/01/20 20:06:58 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data dat;
	dat.id = 95;
	dat.grade = 'A';
	dat.passStat = true;

	uintptr_t raw = Serializer::serialize(&dat);
	Data* restored = Serializer::deserialize(raw);
	
	std::cout << "Data address		:" << &dat << std::endl;
	std::cout << "Seriealized address	:" << raw << std::endl;
	std::cout << "Deserialized address	:" << restored << std::endl;
	std::cout << "restored -> id		:" << restored->id << std::endl;
	std::cout << "restored -> grade	:" << restored->grade << std::endl;
	std::cout << "restored -> passStat	:" << restored->passStat << std::endl;
}