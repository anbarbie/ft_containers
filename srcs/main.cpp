/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:48:14 by antbarbi          #+#    #+#             */
/*   Updated: 2023/02/12 15:25:43 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

int	main()
{
	std::cout << "TEST 1 : MY_VECTOR" << std::endl;
	{
		ft::vector<int> vec;
		ft::vector <int> vec2(5);
	}
	std::cout << std::endl;
	std::cout << "TEST 2 : Real vector" << std::endl;
	std::cout << std::endl;
	{
		std::vector<int> vec(5);
	}
}