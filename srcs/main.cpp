/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:48:14 by antbarbi          #+#    #+#             */
/*   Updated: 2023/02/22 14:03:38 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include "color.hpp"
#include <algorithm>

int	main()
{
	std::cout << BOLDBLUE << "TEST 1 : MY_VECTOR" << RESET << std::endl;
	std::cout << std::endl;
	{
		ft::vector<int> vec;
		vec.reserve(10);
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		
		ft::vector<int> vec2;
		for (int i = 1; i < 5; i++)
			vec2.push_back(i * 100);

		
		PrintContainer(vec);
		PrintContainer(vec2);

		vec.assign(vec2.begin(), vec2.end());
		// vec.assign(vec2.end(), vec2.begin());

		PrintContainer(vec);
		PrintContainer(vec2);
	}
/* 	std::cout << BOLDBLUE << "TEST 2 : Real vector - Capacity test" << RESET << std::endl;
	std::cout << std::endl;
	{
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
/*	std::cout << BOLDBLUE << "TEST 3 : Real vector - Reserve and resize tests" << RESET << std::endl;
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
/*  std::cout << BOLDBLUE << "TEST 4 : Real vector - pop_back test" << RESET << std::endl;
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
/*	std::cout << BOLDBLUE << "TEST 5 : Real vector - pos erase test" << RESET << std::endl;
	std::cout << std::endl;
	//the real vector throws execption when trying to access it + 1 or it + 2
	{
		int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   		int n = sizeof(arr) / sizeof(arr[0]);
		std::vector<int> vec(arr, arr + n);

		std::vector<int>::iterator it = vec.begin();
		std::vector<int>::iterator test;

		for (size_t i = 0; i < 10; i++)
		{
			std::cout << YELLOW << &it[i] << RESET << " ";
			std::cout << *it << " ";
			test = vec.erase(it);
			std::cout << BLUE << &test[i] << RESET << " ";
			std::cout << *test << std::endl;
		}
		std::cout << std::endl;
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
/*	std::cout << BOLDBLUE << "TEST 6 : Real vector - my_class test" << RESET << std::endl;
	std::cout << std::endl;
	{
		std::vector<my_class> vec;
		my_class test;
		vec.push_back(my_class());
		vec.push_back(my_class(3));
		vec.push_back(test);

		std::cout << "Capacity is " << vec.capacity() << std::endl;
		std::cout << "Size is " << vec.size() << std::endl;
		std::cout << vec[0] << std::endl;
		std::cout << vec[1] << std::endl;
		std::cout << vec[2] << std::endl;

		vec.resize(1);
		std::cout << "Capacity is " << vec.capacity() << std::endl;
		std::cout << "Size is " << vec.size() << std::endl;
		std::cout << vec[0] << std::endl;
		std::cout << vec[1] << std::endl;
		std::cout << vec[2] << std::endl;

		for(size_t i = 0; i < vec.size(); i++)
			vec.pop_back();
		std::cout << "Capacity is " << vec.capacity() << std::endl;
		std::cout << "Size is " << vec.size() << std::endl;
	} */
/* 	std::cout << BOLDBLUE << "TEST 7 : Real vector - range erase test" << RESET << std::endl;
	std::cout << std::endl;
	{
		int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   		int n = sizeof(arr) / sizeof(arr[0]);
		std::vector<int> vec(arr, arr + n);

		std::vector<int>::iterator it = vec.begin();
		std::vector<int>::iterator test;

		test = vec.erase(it + 5, it + 7);
		std::cout << "Erase ptr value = " << *test << std::endl;
		std::cout << std::endl;
		PrintContainer(vec);
	} */
/* 	std::cout << BOLDBLUE << "TEST 8 : Real vector - insert test (pos, x)" << RESET << std::endl;
	std::cout << std::endl;
	{
		int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   		int n = sizeof(arr) / sizeof(arr[0]);
		std::vector<int> vec(arr, arr + n);

		// std::vector<int>::iterator it = vec.begin();
		std::vector<int>::iterator test;

		//for loop, test the _capacity adjustement, normal behaviour = x2
		PrintContainer(vec);
		for (size_t i = 10; i < 21; i++)
		{
			test = vec.insert(vec.begin(), 999);
			PrintContainer(vec);
		}
	} */
/* 	std::cout << BOLDBLUE << "TEST 9 : Real vector - insert test (pos, n, x)" << RESET << std::endl;
	std::cout << std::endl;
	{
		int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   		int n = sizeof(arr) / sizeof(arr[0]);
		std::vector<int> vec(arr, arr + n);
		
		std::vector<int>::iterator it = vec.begin();
		std::vector<int>::iterator test;

		PrintContainer(vec);
		vec.insert(it + 10, 3, 999);
		PrintContainer(vec);
	} */
/* 	std::cout << BOLDBLUE << "TEST 10 : Real vector - insert test (pos, first, last)" << RESET << std::endl;
	std::cout << std::endl;
	{
		int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   		int n = sizeof(arr) / sizeof(arr[0]);
		std::vector<int> vec(arr, arr + n);

		std::vector<int> vec2;
		vec2.reserve(3);
		for (int i =1; i < 4; i++)
			vec2.push_back(i * 100);
		
		PrintContainer(vec2);
		PrintContainer(vec);
		vec.insert(vec.begin() + 5, vec2.begin(), vec2.begin() + 3);
		PrintContainer(vec2);
		PrintContainer(vec);
		vec.insert(vec.begin() + 5, vec.begin()+ 2, vec.begin() + 6);
	} */
/* 	std::cout << BOLDBLUE << "TEST 11 : Real vector - swap" << RESET << std::endl;
	std::cout << std::endl;
	{
		int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
   		int n = sizeof(arr) / sizeof(arr[0]);
		std::vector<int> vec(arr, arr + n);

		std::vector<int> vec2;
		vec2.reserve(3);
		for (int i =1; i < 4; i++)
			vec2.push_back(i * 100);
		
		std::vector<int>::iterator it = vec.begin();
		std::vector<int>::iterator it2 = vec2.begin();

		PrintContainer_ptr(vec);
		PrintContainer(vec);
		PrintContainer_ptr(vec2);
		PrintContainer(vec);
		std::cout << "it: " << *it << " it2: " << *it2 << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		vec.swap(vec2);
		PrintContainer_ptr(vec);
		PrintContainer(vec);
		PrintContainer_ptr(vec2);
		PrintContainer(vec);
		std::cout << "it: " << *it << " it2: " << *it2 << std::endl;
	} */
/* 	std::cout << BOLDBLUE << "TEST 12 : Real vector - construct by range" << RESET << std::endl;
	std::cout << std::endl;
	{
		std::vector<int> vec;
		vec.reserve(10);
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);

		// std::vector<int> vec2(vec.begin(), vec.begin());
		// std::vector<int> vec2(vec.end(), vec.begin());
		std::vector<int> vec2(vec.begin(), vec.end());
		
		PrintContainer(vec2);
		PrintContainer_ptr(vec2);
		PrintContainer(vec);
		PrintContainer_ptr(vec);
	} */
/* 	std::cout << BOLDBLUE << "TEST 13 : Real vector - assign(n, const &u)" << RESET << std::endl;
	std::cout << std::endl;
	{
		std::vector<int> vec;
		vec.reserve(10);
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		
		PrintContainer(vec);

		vec.assign(0, 999);
		PrintContainer(vec);
		vec.assign(5, 999);
		PrintContainer(vec);
		vec.assign(15, 999);
		PrintContainer(vec);
	} */
	std::cout << BOLDBLUE << "TEST 14 : Real vector - assign(first, last)" << RESET << std::endl;
	std::cout << std::endl;
	{
		std::vector<int> vec;
		vec.reserve(10);
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		
		std::vector<int> vec2;
		for (int i = 1; i < 5; i++)
			vec2.push_back(i * 100);

		PrintContainer(vec);
		PrintContainer(vec2);

		vec.assign(vec2.begin(), vec2.end());
		// vec.assign(vec2.end(), vec2.begin());

		PrintContainer(vec);
		PrintContainer(vec2);
	}
}