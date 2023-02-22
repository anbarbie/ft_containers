/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:29:18 by antbarbi          #+#    #+#             */
/*   Updated: 2023/02/22 10:32:25 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
 #define FT_CONTAINERS_HPP
 #include <iostream>
 #include <cstring>
 #include <algorithm>
 #include <cstddef>
 #include <vector>
 #include <iterator>

 #include "random_access_iterator.hpp"
 #include "vector.hpp"

 #include "color.hpp"

class my_class
{
	public:

		my_class() {
			_array = new int[10];
			for (int i = 0; i < 10; i++)
				_array[i] = i * 10;
		}
		my_class(size_t n) : _array(new int[10])
		{
			for (int i = 0; i < 10; i++)
				_array[i] = i * n;
		}
		my_class(my_class const &obj) : _array(new int[10]) {
			for (int i = 0; i < 10; i++)
				_array[i] = i * 10;
			*this = obj;
		}
		~my_class() {delete []_array;}

		my_class	&operator =(my_class const &rhs)
		{
			if (this == &rhs)
				return *this;
			for (int i = 0; i < 10; i++)
				_array[i] = rhs._array[i];
			return (*this);
		}

		void	print() const
		{
			for (int i = 0; i < 10; i++)
				std::cout << _array[i] << " ";
			std::cout << std::endl;
		}

	private:

		int	*_array;
};

std::ostream &operator <<(std::ostream &o, my_class const &rhs)
{
	rhs.print();
	return o;
}

template < typename T >
void	PrintContainer(std::vector<T> const &vec)
{
		std::cout << RED << "Cp: " << vec.capacity();
		std::cout << " Sz: " << vec.size() << RESET << std::endl;
		for (size_t i = 0; i < vec.capacity(); i++)
		{
			if (i < vec.size())
				std::cout << vec[i] << " ";
			else if (i < vec.capacity())
				std::cout << BLUE << vec[i] << RESET << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
}

template < typename T >
void	PrintContainer(ft::vector<T> const &vec)
{
		std::cout << RED << "Cp: " << vec.capacity();
		std::cout << " Sz: " << vec.size() << RESET << std::endl;
		for (size_t i = 0; i < vec.capacity(); i++)
		{
			if (i < vec.size())
				std::cout << vec[i] << " ";
			else if (i < vec.capacity())
				std::cout << BLUE << vec[i] << RESET << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
}

template < typename T >
void	PrintContainer_ptr(ft::vector<T> const &vec)
{
		std::cout << RED << "Cp: " << vec.capacity();
		std::cout << " Sz: " << vec.size() << RESET << std::endl;
		for (size_t i = 0; i < vec.capacity(); i++)
		{
			if (i < vec.size())
				std::cout << &vec[i] << " ";
			else if (i < vec.capacity())
				std::cout << BLUE << &vec[i] << RESET << " ";
		}
		std::cout << std::endl;
}

template < typename T >
void	PrintContainer_ptr(std::vector<T> const &vec)
{
	std::cout << RED << "Cp: " << vec.capacity();
	std::cout << " Sz: " << vec.size() << RESET << std::endl;
	for (size_t i = 0; i < vec.capacity(); i++)
	{
		if (i < vec.size())
			std::cout << &vec[i] << " ";
		else if (i < vec.capacity())
			std::cout << BLUE << &vec[i] << RESET << " ";
	}
	std::cout << std::endl;
}

#endif