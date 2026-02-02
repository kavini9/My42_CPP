/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:06:23 by wweerasi          #+#    #+#             */
/*   Updated: 2026/02/02 20:18:12 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _data(new T[0]()), _size(0) { }

template <typename T>
Array<T>::Array(unsigned int size) : _data(new T[size]()), _size(size) { }

template <typename T>
Array<T>::Array(const Array& other) :  _data(new T[other._size]()), _size(other._size) {
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] _data;
}

template <typename T>
T& Array<T>::operator[](const unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("index out of bounds");
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](const unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("index out of bounds");
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}