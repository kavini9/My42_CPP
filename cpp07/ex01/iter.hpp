/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:05:08 by wweerasi          #+#    #+#             */
/*   Updated: 2026/01/31 19:35:42 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include<iostream>

template <typename T, typename F>
void iter(T *arr, const size_t len, F func) {
    for (size_t i = 0; i < len; i++)
        func((arr[i]));
}

// template <typename T, typename F>
// void iter(T *arr, const size_t len, F func) {
//     for (size_t i = 0; i < len; i++)
//         func((arr[i]))
// }

#endif