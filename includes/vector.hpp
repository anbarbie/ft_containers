/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:06:33 by antbarbi          #+#    #+#             */
/*   Updated: 2023/02/22 10:43:40 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
 #define VECTOR_HPP
 #include <memory>
 #include "random_access_iterator.hpp"
 #include <sstream>
 
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
				: _array(NULL), _capacity(n), _max_size(alloc.max_size()), _size(n), _alloc(alloc)
			{
				if (!n)
					return;
				_array = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_array + i, Value);
			}
			// template < class InputIterator >
			// vector(InputIterator first, InputIterator last, const Allocator &alloc = Allocator())
			// {
			// 	;
			// }
			vector(const vector<T,Allocator> &x)
			 	: _array(NULL), _capacity(0), _size(0) {*this = x;}
			~vector() {clear();}
			vector<T,Allocator>& operator=(const vector<T,Allocator>& x)
			{
				if (this == &x)
					return (*this);
				clear();	
				_capacity = x._capacity;
				_max_size = x._max_size;
				_size = x._size;
				_alloc = x._alloc;
				_array = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_array + i, x[i]);
				return (*this);
			}
			// template < class InputIterator >
			// void assign(size_type n, const T& u) {;}
			allocator_type get_allocator() const {return _alloc;}

			  //////////////////////////////////////////////////////////////////////////////////////////////////
			 ///////////////////////////////////////		Iterators		///////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////

			iterator		begin() {return _array;}
			const_iterator	begin() const {return _array;}
			iterator		end()	{return _array + _size;}
			const_iterator	end() const	{return _array + _size;}
			//reverse iterator

			  //////////////////////////////////////////////////////////////////////////////////////////////////
			 ///////////////////////////////////////		Capacity		///////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////

			size_type	size()	const {return _size;}
			size_type	max_size() const {return _max_size;}
			void		resize(size_type sz, T c = T())
			{
				if (sz == _size)
					return ;
				if (sz < _size)
				{
					for (size_t i = sz; i < _size; i++)
						_alloc.destroy(_array + i);
					_size = sz;
				}
				if (sz > _size)
				{
					reserve(sz);
					for (size_t i = _size; i < sz; i++)
						_alloc.construct(_array + i, c);
					_size = sz;
				}
			}
			size_type	capacity() const {return _capacity;}
			bool		empty() const {return _size == 0;}
			void		reserve(size_type n) 
			{
				if (n <= _capacity)
					return ;
				if (n > _max_size)
					throw std::length_error("vector::reserve");
				vector<value_type> tmp(*this);
				clear();
				_capacity = n;
				_array = _alloc.allocate(_capacity);
				for (; _size < tmp._size; _size++)
					_alloc.construct(_array + _size, tmp[_size]);
			}
				
			  //////////////////////////////////////////////////////////////////////////////////////////////////
			 ///////////////////////////////////////		Element access		///////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////

			reference			operator[](size_type n) {return *(_array + n);}
			const_reference		operator[](size_type n) const {return *(_array + n);}
			const_reference		at(size_type n) const
			{
				std::stringstream ss; std::stringstream ss1;
				ss << n; ss1 << _size;
				std::string str = "vector::_M_rangecheck: __n (which is " + ss.str() +
					") >= this->size() (which is " + ss1.str() + ")";
				
				if (n >= _size)
					throw std::out_of_range(str);
				return (*(_array + n));
			}
			reference		at(size_type n) 
			{
				std::stringstream ss; std::stringstream ss1;
				ss << n; ss1 << _size;
				std::string str = "vector::_M_rangecheck: __n (which is " + ss.str() +
					") >= this->size() (which is " + ss1.str() + ")";
			
				if (n >= _size)
					throw std::out_of_range(str);
				return (*(_array + n));
			}
			reference			front() {return *_array;}
			const_reference		front() const {return *_array;}
			reference			back() {return *(_array + _size - 1);}
			const_reference		back() const {return *(_array + _size - 1);}
			pointer				data() {return _array;}
			const_pointer		data() const {return _array;}

			  //////////////////////////////////////////////////////////////////////////////////////////////////
			 ///////////////////////////////////////		Modifiers		///////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////

			void		push_back(const T &x)
			{
				if (_size == 0 && _capacity == 0)
					reserve(1);
				if (_size + 1 <= _capacity)
					_alloc.construct(_array + _size, x);
				if (_size + 1 > _capacity)
				{
					reserve(_capacity * 2);
					_alloc.construct(_array + _size, x);
				}
				++_size;
			}

			void		pop_back() //normally put size to 0 - 1 value and do nothing
			{
				if (_size == 0)	
					return ;
				_alloc.destroy(_array + --_size);
			}

			iterator	erase(iterator position)
			{
				size_t 	i = distance(begin(), position);

				--_size;
				for (; i < _size; i++)
				{
					_alloc.destroy(_array + i);
					_alloc.construct(_array + i, _array[i + 1]);
				}
				return position;
			}

			iterator	erase(iterator first, iterator last)
			{
				if (first == last)
					return first;

				size_t 	len = distance(first, last);
				size_t	i = distance(begin(), first);

				for (iterator it = first; it != last; it++)
				{
					_alloc.destroy(_array + i);
					if (i + len < _size)
					{
						_alloc.construct(_array + i, _array[i + len]);
						_alloc.destroy(_array + (i + len));
					}
					i++;
				}
				_size -= len;
				if (last == end())
					return end();
				return first;
			}

			iterator	insert(iterator position, const T &x) //real segfault when access out of end
			{
				if (_size < distance(begin(), position)) //segfault module changed to return module
					return position;					//real segfault when _capacity < distance during destruct
				if (_size == 0 && _capacity == 0 )
				{
					reserve(1);
					position = begin();
				}
				if (_size + 1 > _capacity)
				{
					size_t len = distance(begin(), position);
					reserve(_capacity * 2);
					position = begin() + len;
				}
				if (_size + 1 <= _capacity)
				{
					size_t	index = distance(begin(), position);
					for (size_t i = _size; i > index; i--)
					{
						if (i != _size)
							_alloc.destroy(&_array[i]);
						_alloc.construct(&_array[i], _array[i - 1]);
					}
					if (index != _size)
						_alloc.destroy(&_array[index]);
					_alloc.construct(&_array[index], x);
				}
				++_size;
				return position;
			}

			void	insert(iterator position, size_type n, const T &x) //capacity is * 2, if it exceeds capacity x2 = custom capac
			{
				if (_size < distance(begin(), position)) 
					return ;
				if (_size == 0 && _capacity == 0 )
				{
					reserve(n);
					position = begin();
				}
				if (_size + n > _capacity)
				{
					size_t len = distance(begin(), position);
					if (_capacity * 2 < _size + n)
						reserve(_size + n);
					else
						reserve(_capacity * 2);
					position = begin() + len;
				}
				if (_size + n <= _capacity)
				{
					size_t	index = distance(begin(), position);
					for (size_t i = _size + n; i > index + n; i--)
					{
						if (i >= _size)
							_alloc.destroy(&_array[i]);
						_alloc.construct(&_array[i], _array[i - n]);
					}
					for (size_t i = index + n; i >= index; i--)
					{
						if (i >= _size)
							_alloc.destroy(&_array[i]);
						_alloc.construct(&_array[i], x);
					}
				}
				_size += n;
			}

			template < class InputIterator >
			void	insert(iterator position, InputIterator first, InputIterator last)
			{ //check if range is not from the same vector else have to deep copy.
				vector<value_type> tmp(*this);
				if (last < first) // check if range is good
					return ;
				for (size_t i = 0; begin() + i != end(); i++)
				{
					if (begin() + i == first)
						first = tmp.begin() + i;
					if (begin() + i == last)
						last = tmp.begin() + i;
				}
				size_t range = distance(first, last);
				if (_size < distance(begin(), position))
					return ;
				if (_size == 0 && _capacity == 0)
				{
					reserve(range);
					position = begin();
				}
				if (_size + range > _capacity)
				{
					size_t len = distance(begin(), position);
					if (_capacity * 2 < _size + range)
						reserve(_size + range);
					else
						reserve(_capacity * 2);
					position = begin() + len;
				}
				if (_size + range <= _capacity)
				{
					size_t	index = distance(begin(), position) - 1;
					for (size_t i = _size + range; i > index + range; i--)
					{
						if (i >= _size)
							_alloc.destroy(&_array[i]);
						_alloc.construct(&_array[i], _array[i - range]);
					}
					InputIterator cp_last = last;
					for (size_t i = index + range; i > index; i--)
					{
						if (i >= _size)
							_alloc.destroy(&_array[i]);	
						_alloc.construct(&_array[i], *--cp_last);
					}
				}
				_size += range;
			}

			void		swap(vector<T,Allocator>&vec)
			{
				pointer			tmp_array = _array;
				size_t			tmp_capacity = _capacity;
				size_t			tmp_max_size = _max_size;
				size_t			tmp_size = _size;
				allocator_type	tmp_alloc = _alloc;
				
				_array = vec._array;
				_capacity = vec._capacity;
				_max_size = vec._max_size;
				_size = vec._size;
				_alloc = vec._alloc;

				vec._array = tmp_array;
				vec._capacity = tmp_capacity;
				vec._max_size = tmp_max_size;
				vec._size = tmp_size;
				vec._alloc = tmp_alloc;
			}

			void		clear()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_array + i);
				_alloc.deallocate(_array, _capacity);
				_array = NULL, _capacity = 0, _size = 0;
			}

			

		private:

			pointer			_array;
			size_t			_capacity;
			size_t			_max_size;
			size_t			_size;
			allocator_type	_alloc;

	};

	////////////////////////////////////////

	template < typename T >
	size_t	distance(ft::random_access_iterator<T> first,ft::random_access_iterator<T> last)
	{
		size_t len = 0;
		for (ft::random_access_iterator<T> it = first; it != last; it++)
			len++;
		return len;
	}
}

#endif