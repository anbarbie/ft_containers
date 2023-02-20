/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:29:18 by antbarbi          #+#    #+#             */
/*   Updated: 2023/02/20 12:46:56 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
 #define FT_CONTAINERS_HPP
 #include <iostream>
 #include <cstring>
 #include <algorithm>
 #include <cstddef>
 #include <vector>

 #include "random_access_iterator.hpp"
 #include "vector.hpp"

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

#endif