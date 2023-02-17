/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:48:14 by antbarbi          #+#    #+#             */
/*   Updated: 2023/02/17 14:31:17 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include "color.hpp"

int	main()
{
	std::cout << "TEST 1 : MY_VECTOR" << std::endl;
	{
		ft::vector<int> vec;
		vec.reserve(10);
		for (size_t i = 0; i < 10; i++)
			vec.push_back(i * 10);

		ft::vector<int>::iterator it = vec.begin();

		// for (size_t i = 0; i < 10; i++)
			vec.erase(it);

		std::cout << "Capacity is " << vec.capacity() << std::endl;
		std::cout << "Size is " << vec.size() << std::endl;
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
	// std::cout << std::endl;
	// std::cout << "TEST 2 : Real vector - Capacity test" << std::endl;
	// std::cout << std::endl;
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
/* 	std::cout << std::endl;
	std::cout << "TEST 3 : Real vector - Reserve and resize tests" << std::endl;
	std::cout << std::endl;
	{
		int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   		int n = sizeof(arr) / sizeof(arr[0]);
		std::vector<int> vec(arr, arr + n);

		std::cout << "Capacity is " << vec.capacity() << std::endl;
		std::cout << "Size is " << vec.size() << std::endl;
		for (size_t i = 0; i < vec.capacity(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;
		
		vec.resize(5);
		std::cout << "Capacity is " << vec.capacity() << std::endl;
		std::cout << "Size is " << vec.size() << std::endl;
		for (size_t i = 0; i < vec.capacity(); i++)
		{
			if (i < vec.size())
				std::cout << vec[i] << " ";
			else if (i < vec.capacity())
				std::cout << BLUE << vec[i] << RESET << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		vec.resize(8);
		std::cout << "Capacity is " << vec.capacity() << std::endl;
		std::cout << "Size is " << vec.size() << std::endl;
		for (size_t i = 0; i < vec.capacity(); i++)
		{
			if (i < vec.size())
				std::cout << vec[i] << " ";
			else if (i < vec.capacity())
				std::cout << BLUE << vec[i] << RESET << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	} */

						// 	std::string input;
						// do 
						// {
						// 	if (input == "exit")
						// 		break;
						// 	if (input == "q")
						// 	{
						// 		size_t cap = vec.size();
						// 		for (size_t i = 0; i <= cap; i++)
						// 			vec.push_back(999);
						// 		std::cout << "Size is " << vec.size() << std::endl;
						// 		std::cout << "Capacity is " << vec.capacity() << std::endl;
						// 	}
						// } while (std::getline(std::cin, input));

/* 	std::cout << std::endl;
	std::cout << "TEST 4 : Real vector - pop_back test" << std::endl;
	std::cout << std::endl;
	{
		int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   		int n = sizeof(arr) / sizeof(arr[0]);
		std::vector<int> vec(arr, arr + n);

		std::cout << "Capacity is " << vec.capacity() << std::endl;
		std::cout << "Size is " << vec.size() << std::endl;
		for (size_t i = 0; i < vec.capacity(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
		std::cout << std::endl;

		for (int i = 10; i > 0; i--)
			vec.pop_back();
		std::cout << "Capacity is " << vec.capacity() << std::endl;
		std::cout << "Size is " << vec.size() << std::endl;
		for (size_t i = 0; i < vec.capacity(); i++)
		{
			if (i < vec.size())
				std::cout << vec[i] << " ";
			else if (i < vec.capacity())
				std::cout << BLUE << vec[i] << RESET << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		
		vec.pop_back();
		vec.pop_back();
		std::cout << "Capacity is " << vec.capacity() << std::endl;
		std::cout << "Size is " << vec.size() << std::endl;
		for (size_t i = 0; i < vec.capacity(); i++)
		{
			if (i < vec.size())
				std::cout << vec[i] << " ";
			else if (i < vec.capacity())
				std::cout << BLUE << vec[i] << RESET << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	} */
	
	std::cout << std::endl;
	std::cout << "TEST 5 : Real vector - pop_back test" << std::endl;
	std::cout << std::endl;
	{
		int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   		int n = sizeof(arr) / sizeof(arr[0]);
		std::vector<int> vec(arr, arr + n);

		std::vector<int>::iterator it = vec.begin();

		for (size_t i = 0; i < 10; i++)
			vec.erase(it);

		std::cout << "Capacity is " << vec.capacity() << std::endl;
		std::cout << "Size is " << vec.size() << std::endl;
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
}