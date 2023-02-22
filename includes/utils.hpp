/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:41:47 by antbarbi          #+#    #+#             */
/*   Updated: 2023/02/22 13:17:26 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
 #define UTILS_HPP

namespace ft
{

	  //////////////////////////////////////////////////////////////////////////////////////////////////
	 ///////////////////////////////////////		Enable_if		///////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////

	template < bool Condition, typename T = void >
	struct enable_if {};

	template < typename T >
	struct enable_if<true, T> { typedef T type;};

	template <class T> struct is_integral {static const bool value = false;};
	template <> struct is_integral<bool> {static const bool value = true;};
	template <> struct is_integral<char> {static const bool value = true;};
	template <> struct is_integral<signed char> {static const bool value = true;};
	template <> struct is_integral<unsigned char> {static const bool value = true;};
	template <> struct is_integral<float> {static const bool value = true;};
	template <> struct is_integral<double> {static const bool value = true;};
	template <> struct is_integral<long double> {static const bool value = true;};
	template <> struct is_integral<short> {static const bool value = true;};
	template <> struct is_integral<unsigned short> {static const bool value = true;};
	template <> struct is_integral<int> {static const bool value = true;};
	template <> struct is_integral<unsigned int> {static const bool value = true;};
	template <> struct is_integral<long> {static const bool value = true;};
	template <> struct is_integral<unsigned long> {static const bool value = true;};
	template <> struct is_integral<long long> {static const bool value = true;};
	template <> struct is_integral<unsigned long long> {static const bool value = true;};

	  //////////////////////////////////////////////////////////////////////////////////////////////////
	 ///////////////////////////////////////		distance		///////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////

	template < typename T >
	size_t	distance(ft::random_access_iterator<T> first,ft::random_access_iterator<T> last) { return last - first; }
}

#endif