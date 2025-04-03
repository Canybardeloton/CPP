/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiliber <agiliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:17:31 by agiliber          #+#    #+#             */
/*   Updated: 2025/04/03 12:06:21 by agiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <exception>

template <typename T>
class Array
{
	public:
		Array() : _array(nullptr), _size(0)
		{
			std::cout << "Array created" << std::endl;
		}

		Array(unsigned int n) : _size(n)
		{
			_array = new T[n];
			std::cout << "Array created of size " << n << std::endl;
		}

		Array(const Array& copy) : _size(copy._size)
		{
			memcpy(this->_array, copy._array, _size * sizeof(T));
			std::cout << "Array created by copy" << std::endl;
		}

		Array&	operator=(const Array& copy)
		{
			if (this != &copy)
			{
				delete[] _array;
				_size = copy._size;
				_array = new T[_size];
				memcpy(this->_array, copy._array, _size * sizeof(T));
				std::cout << "Array created by assignement" << std::endl;
			}
			return (*this);
		}

		~Array()
		{
			delete [] _array;
			std::cout << "Array destroyed" << std::endl;
		}

		unsigned long	size(void)
		{
			return (_size);
		}

		T&	operator[](unsigned long index)
		{
			if (index >= _size)
				throw (std::exception("Index out of bounds"));
			return (_array[index]);
		}

	private:
		unsigned long	_size;
		T	_array;
};
