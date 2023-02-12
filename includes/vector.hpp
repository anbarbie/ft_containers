/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:06:33 by antbarbi          #+#    #+#             */
/*   Updated: 2023/02/12 15:30:31 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
 #define VECTOR_HPP
 #include <memory>
 #include "random_access_iterator.hpp"
 
namespace ft
{
	template < class T, class Allocator=std::allocator<T> >
	class vector
	{
		public:

			typedef				T										value_type;
			
			typedef				ft::random_access_iterator< T >			iterator;
			typedef				ft::random_access_iterator< const T >	const_iterator;
			
			typedef				size_t									size_type;
			typedef 			ptrdiff_t								difference_type;
			
			typedef				Allocator								allocator_type;
			typedef typename	Allocator::reference					reference;
			typedef typename	Allocator::const_reference				const_reference;
			typedef typename	Allocator::pointer						pointer;
			typedef typename	Allocator::const_pointer				const_pointer;

			explicit vector(const Allocator &alloc = Allocator())
				: _array(NULL), _capacity(0), _max_size(alloc.max_size()), _size(0), _alloc(alloc) {};
			explicit vector(size_type n, const T &Value = T(), const Allocator &alloc = Allocator())
				: _array(NULL), _capacity(0), _max_size(alloc.max_size()), _size(0), _alloc(alloc)
			{
				if (!n)
					return;
				_array = _alloc.allocate(n);
				_capacity = n;
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_array + i, Value);
			}
			// template < class InputIterator >
			// vector(InputIterator first, InputIterator last, const Allocator& = Allocator());
			// vector(const vector<T,Allocator> &x);
			~vector()
			{
				_alloc.destroy(_array);
				_array = _alloc.deallocate(_array, _capacity);
			};
			// vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
			// template < class InputIterator >
			// void assign(size_type n, const T& u);
			// allocator_type get_allocator() const;

			  //////////////////////////////////////////////////////////////////////////////////////////////////
			 ///////////////////////////////////////		Iterators		///////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////

			

		private:

			pointer			_array;
			size_t			_capacity;
			size_t			_max_size;
			size_t			_size;
			allocator_type	_alloc;

	};
}

#endif