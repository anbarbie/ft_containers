/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:29:18 by antbarbi          #+#    #+#             */
/*   Updated: 2023/02/12 15:20:41 by antbarbi         ###   ########.fr       */
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

template < class T >
class my_vector
{
	public:

		my_vector() {
			for (T i = 0; i < 10; i++)
				_array[i] = i * 10;
		}
		my_vector(my_vector const &obj) {*this = obj;}
		~my_vector() {};
		
		typedef	ft::random_access_iterator<T>		iterator;
		typedef ft::random_access_iterator<const T>	const_iterator;

		iterator	begin() {return &_array[0];}
		iterator	end() {return	&_array[10];}
		const_iterator	cbegin() const {return &_array[0];}
		const_iterator	cend() const {return	&_array[10];}
   
	private:

		T	_array[10];
};

#endif