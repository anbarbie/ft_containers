/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:42:08 by antbarbi          #+#    #+#             */
/*   Updated: 2023/02/09 18:13:38 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
 #define RANDOM_ACCESS_ITERATOR_HPP

//////////////////////////////////
 #include <iostream>
 #include <cstring>
 #include <algorithm>
 #include <cstddef>
/////////////////////////////////

namespace ft
{

	template < class Category, class Type, class Distance = ptrdiff_t, class Pointer = Type*, class Reference = Type& >
	struct iterator
	{
		typedef		Distance 	difference_type;
		typedef		Type 		value_type;
		typedef		Pointer 	pointer;
		typedef		Reference	reference;
		typedef		Category 	iterator_category;
	};

	struct output_iterator_tag {};
	struct input_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template < class Iter >
	struct iterator_traits
	{
		typedef typename	Iter::difference_type		difference_type;
		typedef typename	Iter::value_type			value_type;
		typedef typename	Iter::pointer				pointer;
		typedef typename	Iter::reference				reference;
		typedef typename	Iter::iterator_category		iterator_category;
	};

	template < class T >
	struct iterator_traits< T* >
	{
		typedef				std::ptrdiff_t				difference_type;
		typedef				T							value_type;
		typedef				T*							pointer;
		typedef				T&							reference;
		typedef				random_access_iterator_tag	iterator_category;
	};

	template < class T >
	struct iterator_traits< const T* >
	{
		typedef				std::ptrdiff_t				difference_type;
		typedef				T							value_type;
		typedef				const T*					pointer;
		typedef				const T&					reference;
		typedef				random_access_iterator_tag	iterator_category;
	};

	template < class T >
	class random_access_iterator : public ft::iterator<random_access_iterator_tag, T>
	{
		public:

			typedef typename	ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename	ft::iterator<random_access_iterator_tag, T>::value_type			value_type;
			typedef typename	ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
			typedef typename	ft::iterator<random_access_iterator_tag, T>::reference			reference;
			typedef typename	ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;

			random_access_iterator() : m_ptr(NULL) {};
			random_access_iterator(pointer p) : m_ptr(p) {};
			random_access_iterator(random_access_iterator const &obj) {*this = obj;}
			~random_access_iterator() {};

			random_access_iterator &operator = (random_access_iterator const &obj) {
				if (this != &obj)
					m_ptr = obj.m_ptr;
				return (*this);
			}

			const pointer		base() const {return m_ptr;}

			  ////////////////////////////////////////////////////////////////////////////////////////////////////////
			 ///////////////////////////////////////		In/Decrement		/////////////////////////////////////
			////////////////////////////////////////////////////////////////////////////////////////////////////////

			random_access_iterator	&operator	++() {m_ptr++; return *this;}
			random_access_iterator	&operator	--() {m_ptr--; return *this;}
			random_access_iterator	operator	++(int) {
				random_access_iterator tmp(*this);
				++(*this);
				return tmp;
			}
			random_access_iterator	operator	--(int) {
				random_access_iterator tmp(*this);
				--(*this);
				return tmp;
			}

			  //////////////////////////////////////////////////////////////////////////////////////////////////
			 ///////////////////////////////////////		Dereference		///////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////

			reference	&operator	*() const {return *m_ptr;}
			pointer		&operator	->() const {return m_ptr;}

			  //////////////////////////////////////////////////////////////////////////////////////////////////
			 ///////////////////////////////////////		Offset		///////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////

			reference	operator [](const difference_type i) const {return *(m_ptr + i);}

			  //////////////////////////////////////////////////////////////////////////////////////////////////
			 ///////////////////////////////////////		Arithmetic		///////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////

			difference_type			operator	-(const random_access_iterator &rhs) const {return m_ptr - rhs.m_ptr;}
			random_access_iterator	operator	-(const difference_type &rhs) const {return m_ptr - rhs;}
			random_access_iterator	operator	+(const	difference_type &rhs) const {return m_ptr + rhs;}

			  //////////////////////////////////////////////////////////////////////////////////////////////////
			 ///////////////////////////////////////		Compound		///////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////

			random_access_iterator	operator	+=(const difference_type &rhs) {m_ptr += rhs; return *this;}
			random_access_iterator	operator	-=(const difference_type &rhs) {m_ptr -= rhs; return *this;}

		private:

			pointer	m_ptr;

	};

	template < class T >
	bool	operator ==(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return ((rhs.base() == lhs.base()));
	}

	template < class T, class U >
	bool	operator ==(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return ((rhs.base() == lhs.base()));
	}

	template < class T >
	bool	operator !=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return ((rhs.base() != lhs.base()));
	}

	template < class T, class U >
	bool	operator !=(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return ((rhs.base() != lhs.base()));
	}

	template < class T >
	bool	operator	<(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template < class T, class U >
	bool	operator	<(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template < class T >
	bool	operator	<=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template < class T, class U >
	bool	operator	<=(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template < class T >
	bool	operator	>(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template < class T, class U >
	bool	operator	>(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template < class T >
	bool	operator	>=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template < class T, class U >
	bool	operator	>=(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template < class T >
	ft::random_access_iterator<T> operator +(const typename iterator<random_access_iterator_tag, T>::difference_type lhs,
		const random_access_iterator<T> &rhs)
	{
		return (lhs + rhs.base());
	}
}

#endif