#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory> //allocator call
#include "utils.hpp" //ft_nullptr, enable_if, is_integral
#include "reverse_iterator.hpp"
#include "random_access_iterator.hpp"

namespace ft {
    template <typename T, typename Allocator = std::allocator<T> >  
    //std::allocator사용하라는 subject
    class vector {
        public:
		// Member types ======================================================================================

            typedef T                                           value_type;
            // 컨테이너에 담을 변수 타입 저장

            // * allocate는 템플릿으로 만들어야 하며, 템플릿 매개변수에는 할당하고자 하는 객체의 타입 T를 사용한다.
            // * pointer(T*)와 reference(T&)라는 typedef를 제공해야한다.
            typedef Allocator										allocator_type;
            typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
            // allocator의 타입과 reference, pointer allocator_type에서 끄집어오기
            
            typedef typename allocator_type::size_type				size_type;
			typedef typename allocator_type::difference_type		difference_type;
            // size_t, ptrdiff_t (두 포인터를 뺀 결과의 부호 있는 정수 유형)


			// iterator 구현하기
            typedef ft::random_access_iterator<value_type>			iterator;
            typedef ft::random_access_iterator<const value_type>	const_iterator;
            typedef ft::reverse_iterator<iterator>					reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
            // 위의 iterator를 받아오지 않고 T만 받아오면 reverse_iterator에서 random iterator에서 구현한 것을 한번더 구현을 해야한다.
			// 그래서 편의상 iterator를 template으로 받아 버리자!

			// random iterator
			// reverse iterator >> 공부하기 대충은 ok

        // ===================================================================================================

        private:
        // Member variables ==================================================================================
            allocator_type  _alloc;
            pointer         _start;
            pointer         _end;
            pointer         _capa_end;
            // start : 벡터 배열
            // end : 벡터의 현재 위치
            // end_of_capacity : 벡터 저장공간의 마지막 위치

		// ===================================================================================================

        public:
		// Constructors ======================================================================================

			// default construct : 요소가 없는 빈 컨테이너

            explicit vector(const allocator_type& alloc = allocator_type())
            : _alloc(alloc), _start(ft_nullptr), _end(ft_nullptr), _capa_end(ft_nullptr) 
			{}
			// explicit 이란 : 형변환 제한을 둔다 원하는 대로 안들어오면 터트린다!
            // null, 0, >> 을 대신할 ft_nullptr을 만들자!
            //allocator의 변수 말고 멤버 함수에 대해서 알아보자!
            

			// fill construct : n개의 요소로 구성된 컨테이너. 각 요소는 val의 복사본
            // 객체의 생성자 호출하면 > 인스턴스화 된 객체가 value에 대입
            explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type())
            : _alloc(alloc), _start(ft_nullptr), _end(ft_nullptr), _capa_end(ft_nullptr)
            {
                this->_start = this->_alloc.allocate(n);
                this->_end = this->_start;
                this->_capa_end = this->_start + n;
                
                //while (n--)
                for (size_type i = 0; i < n; i++)
                    this->_alloc.construct(this->_end++, value); // 각 요소는 val의 복사본
            }
			// value_type() 이라는 생성자 호출! ex) int() 이런식으로 공간을 형성
			// vector<int> a(5,4);

			// int 형 공간 5개만들고 4넣기!


			// range construct : range[first, last) 와 같은 수의 요소로 구성된 컨테이너. 각 요소는 해당 범위의 해당 효소의 순서로 구성된다.
            template <typename InputIterator>
            explicit vector(InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type(),
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr)
            : _alloc(alloc)
            {
                size_type n = ft::distance(first, last);
                // distance 두 이터레이터 사이의 거리 구하기! distance 구현하기!
                this->_start = this->_alloc.allocate(n);
                this->_end = this->_start;
                this->_capa_end = this->_start + n;

                for (size_type i = 0; i < n; i++)
                    this->_alloc.construct(this->_end++, *(first++));
            }
			// 여기서 사용하는 이유는 > ft::enable_if 에 대해서 알아보자! > 만들어도 보자!
			// iterator구간으로 대입하는 것이어서 template타입에 따라 이함수가 시행이 되어야 되는지 안되어애 하는지를 확인을 해
			// 주어야 한다.

			// is_integral 을 만들자! > 어떻게 동작을 하는지도 알아보자!
			// is_integral 으로 type 하나 받고 > is_integral_base <t or f, type> {}; value 와 type 이 정해진다
			// value값이 참이면 integral에 속하는 것!
			//여기서는 !니까 integral이 아닐때! InputIterator을 type으로 가지고 그 타입에 ft_nullptr을 대입을 한다.


			// copy construct : other에 있는 각 요소의 복사본을 같은 순서로 구성한 컨테이너
            vector(const vector& other)
			// alloc이 맨처음에 있어야 된다.
            : _alloc(other._alloc), _start(ft_nullptr), _end(ft_nullptr), _capa_end(ft_nullptr)
            {
                size_type n = other.size(); //구현했다
                this->_start = this->_alloc.allocate(n);
                this->_end = this->_start;
                this->_capa_end = this->_start + n;
                pointer p = other._start;

                for (size_type i = 0; i < n; i++)
                    this->_alloc.construct(this->_end++, *(p++));
            }

			// 각 요소에 대한 저장 공간은 allocator를 사용해 할당된다.

			// assignemt operator
            vector& operator=(const vector& other)
            {
                if (this != &other)
                {
					// 구현했다.
                    this->clear();
                    // insert(_start, other.begin(), other.end()); // 다 지우고 삽입
                }
                return (*this);
            }

			// destructor
            ~vector()
            {
                this->clear();
                _alloc.deallocate(_start, this->capacity());
            }

 		// ===================================================================================================
           
		// Iterators =========================================================================================

			// begin 벡터의 첫 번째 요소에 대한 반복자 반환
			// end : 벡터의 끝(마지막 요소 다음)에 대한 반복자 반환
            iterator begin() { return (_start); }
            const_iterator begin() const { return (_start); }
            iterator end() { return (_end); }
            const_iterator end() const { return (_end); }

			// *********************	
			// *********************
            // 여기 고민해보기
            reverse_iterator rbegin() { return (reverse_iterator(_end)); }
            const_reverse_iterator rbegin() const { return (reverse_iterator(_end)); }
            reverse_iterator rend() { return (reverse_iterator(_start)); }
            const_reverse_iterator rend() const { return (reverse_iterator(_start)); }
			// 호출을 어떤 식으로 하는 걸까
			// *********************
			// *********************

		// ===================================================================================================

		// Capacity ==========================================================================================
    
			// vector가 비었을때
			bool empty() const { return (_start == _end); }

			// return size
			size_type size() const { return (_end - _start); } // vector(const vector& other)에서 사용
			
			// 사용가능한 메모리가 모두 사용되기 전에 allocator 클래스의 객체가 할당할 수 있는 type형식의 요소 수, allocator 함수
			size_type max_size() const { return (_alloc.max_size()); } // std::allocator 멤버함수
			
			// element의 갯수가 아닌, 할당받은 메모리의 갯수
			size_type capacity() const { return (_capa_end - _start); }

		// reserve, resize, at, const at, assign 2, insert 3, push_back, pop_back,
		// erase 2, swap, clear,, relational operators

			// 벡터의 용량(재할당 없이 벡터가 보유할 수 있는 총 요소 수)보다 크거나 같은 값으로 늘 new_cap한다.
			// 현재 capacity() new_cap보다 크면 새 스토리지가 할당되고, 그렇지 않으면 함수가 아무 작업도 수행하지 않는다.
			void reserve(size_type n)
			{
				if (n > this->max_size())
					throw std::length_error("ft::vector::reserve: n > max_size()");
				if (n > this->capacity())
				{
					pointer prev = _start;
					pointer prev_end = _end;
					size_type prev_capa = this->capacity();
					size_type prev_size = this->size();

					_start = _alloc.allocate(n);
					_end = _start;
					_capa_end = _start + n;
					while(prev != prev_end)
						_alloc.construct(_end, *prev);
						_alloc.destroy(prev);
						++_end;
						++prev;
					}
					_alloc.deallocate(prev - prev_size, prev_capa);
				}
			}

			// n이 현재 컨테이너 크기보다 작으면, 그 이상의 요소를 제거하고 크기를 축소
			// n이 현재 컨테이너 크기보다 크면, n의 크기만큼 새로운 값을 삽입한다. value가 지정되면 새 요소가 value의 복사본으로 초기화 되고, 그렇지 않으면 값이 초기화된다.
			void resize(size_type n, value_type val = value_type())
			{
				if (n > this->max_size())
					throw std::length_error("ft::vector::resize: n > max_size()");
				if (this->size() == n)
					return ;
				// 여기 부분이해하기!
				if (n < this->size())
				{
					while (this->size() != n)
						pop_back();
				}
				else
				{
					if (this->capacity() * 2 < n)
						reserve(n);
					while (this->size() != n)
						push_back(val);
				}
			}

		// ===================================================================================================

		// Element Access ====================================================================================

		// 배열처럼 접근하여 인덱스에 대한 참조 반환
		reference operator[](size_type n) { return (_start[n]); }
		
		const_reference operator[](size_type n) const { return (_start[n]); }
		
		// reference		at(size_type n)
		// {

		// }
		
		// 벡터의 n위치에 있는 요소에 대한 참조를 반환, n은 값이 아니라 위치!
		// 이 함수는 n이 벡터에서 유효한 요소의 범위 내에 있는지 여부를 자동으로 검사하고 그렇지 않으면 out_of_range 예외를 던진다.
		// 이는 out_of_range 대해 검사하지 않는 멤버 연산자[]와 대조된다.

		// const_reference at(size_type n) const
		// {

		// }

		// 첫번째 원소
		reference front() { return (*_start); }
		const_reference front() const { return (*_start); }

		// 마지막 원소
		reference back() { return (*(_end - 1)); }
		const_reference back() const { return (*(_end - 1)); }
		// end는 마지막을 가리키고 있어서

		// ===================================================================================================

		// Modifiers =========================================================================================

		// 벡터에 새 내용을 할당하고 현재 내용을 교체하고 그에 따라 크기를 수정한다.
		// template <class InputIterator>
		// void assign(InputIterator first, InputIterator last,
		// typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr)
		// {

		// }

		// void assign(size_type n, const value_type& val)
		// {

		// }

		// insert,,
		// 1. single element
		// iterator insert(iterator postion, const value_type& val)
		// {

		// }

		// 2.fill
		// void insert(iterator position, size_type n, const value_type& val)
		// {

		// }

		// 3.range
		// template<class InputIterator>
		// void insert(iterator position, InputIterator first, InputIterator last,
		// typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr)
		// {

		// }

		// 벡터의 뒤에 새로운 element를 추가한다.
		// 늘어난 벡터의 크기가 capacity를 넘어갈 경우, 이전 capacity * 2의 크기로 늘어남
		void push_back(const value_type& val)
		{
			if (_end == _capa_end)
			{
				size_type size = this->size();
				if (size == 0)
					this->reserve(1);
				else
					this->reserve(2 * size);
			}
			_alloc.construct(_end, val);
			_end++;
		}

		// 벡터의 맨 뒤 요소를 하나 제거한다.
		void pop_back()
		{
			if (this->size() != 0)
			{
				_alloc.destory(--_end);
			}
		}

		//erase,,
		// 1.signle element
		// iterator erase(iterator pos)
		// {

		// }

		// 2. range
		// iterator erase(iterator first, iterator last)
		// {

		// }

		void swap(vector& other)
		{
			pointer		tmp_start = _start;
			pointer		tmp_end = _end;
			pointer		tmp_capa_end = _capa_end;
			allocator_type tmp_alloc = _alloc;

			_start = other._start;
			_end = other._end;
			_capa_end = other._capa_end;
			_alloc = other._alloc;

			other._start = tmp_start;
			other._end = tmp_end;
			other._capa_end = tmp_capa_end;
			other._alloc = tmp_alloc;
		}
		
		void clear()
		{
			while (_start != _end)
			{
				_alloc.destroy(--_end);
			}
		}

		// ======================================================================================================================

		// Allocator ============================================================================================================

		//**************************************************************
		
		// 벡터와 연결된 할당자 객체의 복사본을 반환한다.
		// 진베 왈 : 외부에서 만들어 놓은 하나(이상)의 인자를 이미 만들어놓은 벡터의 allocator 안에 넣기 위함?
		allocator_type get_allocator() const {
			return allocator_type();
		}
		// 
		//**************************************************************

		// ======================================================================================================================
    };

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		typename ft::vector<T>::const_iterator first1 = lhs.begin();
		typename ft::vector<T>::const_iterator first2 = rhs.begin();

		while (first1 != lhs.end())
		{
			if (*(first1++) != *(first2)++)
				return false;
		}
		return (true);
	}

// relational operators =========================================================================================================

// lexicographical_compare을 쓰는이유?

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc>&lhs, const vector<T, Alloc>&rhs)
	{ return !(lhs == rhs); }

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc>&lhs, const vector<T, Alloc>&rhs)
	{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc>&lhs, const vector<T, Alloc>&rhs)
	{ return !(rhs < lhs); }

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc>&lhs, const vector<T, Alloc>&rhs)
	{ return (rhs < lhs); }

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc>&lhs, const vector<T, Alloc>&rhs)
	{ return !(lhs < rhs); }


// ============================================================================================================================== 

	// 두 vector를 바꾸는!
	template <class T, class Alloc>
	void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}

} // namespace ft

#endif