/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:24:49 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/09 22:08:47 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::const_iterator easyfind(const T& container, const int val) {
    return std::find(std::begin(container), std::end(container), val);
}

template<typename T>
typename T::iterator easyfind(T& container, const int val) {
    return std::find(std::begin(container), std::end(container), val);
}

#endif