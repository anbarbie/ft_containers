/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:18:33 by antbarbi          #+#    #+#             */
/*   Updated: 2023/02/09 18:25:30 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

#include "test.hpp"

int	main()
{
	std::cout << "MY VEC" << std::endl;
	{
		my_vector<int> vec;
		my_vector<int> vec2;

		my_vector<int>::iterator it = vec.begin();
		my_vector<int>::iterator ite = vec.end();

		my_vector<int>::const_iterator it2 = vec2.cbegin();
		my_vector<int>::const_iterator ite2 = vec2.cend();

		// for (; it != ite; it++)
		// 	std::cout << *it << std::endl;

		std::cout << *(it + 3) + 4 << std::endl;
		std::cout << ite - it << std::endl;
		std::cout << *(5 + it) << std::endl;
		std::cout << (it >= ite) << std::endl;
		std::cout << *(ite - 6) << std::endl;
		std::cout << std::endl;
		it += 1;
		std::cout << *it << std::endl;
		it -= 1;
		*it = 5;
		std::cout << *it << std::endl;
		std::cout << std::endl;
		std::cout << (it == it2) << std::endl;
		std::cout << (ite == ite2) << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << it2[i] << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << *(it2 + i) << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "REAL VEC" << std::endl;
	{
		int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   		int n = sizeof(arr) / sizeof(arr[0]);
		
		std::vector<int> vec(arr, arr + n);

		int arr2[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   		int n2 = sizeof(arr2) / sizeof(arr2[0]);

		std::vector<int> vec2(arr2, arr2 + n2);
		
		std::vector<int>::iterator it = vec.begin();
		std::vector<int>::iterator ite = vec.end();

		std::vector<int>::const_iterator it2 = vec2.begin();
		std::vector<int>::const_iterator ite2 = vec2.end();

		std::cout << *(it + 3) + 4 << std::endl;
		std::cout << ite - it << std::endl;
		std::cout << *(5 + it) << std::endl;
		std::cout << (it >= ite) << std::endl;
		std::cout << *(ite - 6) << std::endl;
		std::cout << std::endl;
		it += 1;
		std::cout << *it << std::endl;
		it -= 1;
		std::cout << *it << std::endl;
		std::cout << std::endl;
		std::cout << (it >= it2) << std::endl;
		std::cout << (ite >= ite2) << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << it2[i] << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << *(it2 + i) << std::endl;
	}
}