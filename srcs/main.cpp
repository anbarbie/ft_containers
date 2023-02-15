/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:48:14 by antbarbi          #+#    #+#             */
/*   Updated: 2023/02/15 17:09:27 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

int	main()
{
	std::cout << "TEST 1 : MY_VECTOR" << std::endl;
	{
		ft::vector<int> vec;
		vec.reserve(10);
		std::cout << "Capacity is " << vec.capacity() << std::endl;
		for (size_t i = 0; i < vec.capacity(); i++)
			vec[i] = i * 10;
		std::cout << "Size is " << vec.size() << std::endl;
		for (size_t i = 0; i < vec.capacity(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;
		vec.resize(10);
		for (unsigned int i = 0; i < vec.capacity(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "TEST 2 : Real vector - Capacity test" << std::endl;
	std::cout << std::endl;
/* 	{
		int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   		int n = sizeof(arr) / sizeof(arr[0]);
		std::vector<int> vec(arr, arr + n);

		std::cout << "size is " << vec.size() << std::endl;
		std::cout << "capacity is " << vec.capacity() << std::endl;
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;
		vec.resize(2);
		std::cout << "size is " << vec.size() << std::endl;
		std::cout << "capacity is " << vec.capacity() << std::endl;
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;
		vec.resize(12);
		std::cout << "size is " << vec.size() << std::endl;
		std::cout << "capacity is " << vec.capacity() << std::endl;
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;
		vec.reserve(50);
		std::cout << "size is " << vec.size() << std::endl;
		std::cout << "capacity is " << vec.capacity() << std::endl;
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;
	} */
	std::cout << std::endl;
	std::cout << "TEST 3 : Real vector - Element access test" << std::endl;
	std::cout << std::endl;
	{
		int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   		int n = sizeof(arr) / sizeof(arr[0]);
		std::vector<int> vec(arr, arr + n);

		std::cout << "Capacity is " << vec.capacity() << std::endl;
		for (size_t i = 0; i < vec.capacity(); i++)
			vec[i] = i * 10;
		std::cout << "Size is " << vec.size() << std::endl;
		for (size_t i = 0; i < vec.capacity(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;
		vec.resize(5);
		for (unsigned int i = 0; i < vec.capacity(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
	}

}