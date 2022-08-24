#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory> // allocator
// #include <stdexcept>
// #include "random_access_iterator.hpp"
// #include "reverse_iteraotr.hpp"
#include "utils.hpp" //ft_nullptr, enable_if

namespace ft
{
    template < typename T, typename Allocator = std::allocator<T> >
    class vector
    {
        public:
            // value_type : 컨테이너에 담을 변수 타입
            // allocator_type : allocator타입과 reference, pointer
            // size_type : Unsinged integer type
            // difference_type : Signed integer type, 노드 간 거리 연산을 위한 타입
            // iterator : 순환자
            // const_iterator : 참조된 값을 바꿀 수 없다.
            // reverse_iterator : 제일 마지막이 begin, ++연산을 하면 역순으로 연산

        // Member types ======================================================================================
            
            typedef T                                           value_type;
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            

            //야는 T를 받고
            // 야는 왜 iterator를 받니?
            // 멋져 간략화하기 위함 만들어 논거 쓰기 위해서
            typedef ft::random_access_iterator<T>               iterator;
            typedef ft::random_access_iterator<const T>         const_iterator;
            
            // 구조
            //위의 것을 받아오지 않고 T만 받아오면 reverse_iterator에서 random iterator에서 구현한 것을 한번더 구현을 해야한다.
            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
            
            typedef typename allocator_type::size_type          size_type; // size_t
            typedef typename allocator_type::difference_type    difference_type; //ptr_diff_t 두 포인터를 뺀 결과의 부호 있는 정수 유형

        // ===================================================================================================

            // value
            // start : 벡터 배열
            // end : 벡터의 현재 위치
            // end_of_capacity : 벡터 저장공간의 마지막

        protected:
        // Member variables ==================================================================================

            allocator_type      _alloc;         // Allocator 변수
            pointer             _start;
            pointer             _end;
            pointer             _end_of_capacity;
        // ===================================================================================================        
        
        public:

            // default construct : 요소가 없는 빈 컨테이너
            // fill construct : n개의 요소로 구성된 컨테이너, 각 요소는 val의 복사본이다.
            // range construct : range[first, last)와 같은 수의 요소로 구성된 컨테이너, 각 요소는 해당 범위의 해당 요소의 순서로 구성된다.
            // copy construct : x에 있는 각 요소의 복사본을 같은 순서로 구성한 컨테이너
            // 각 요소에 대한 저장 공간은 allocator를 사용해 할당된다.
            // destruct

            // default constructor
            explicit vector(const allocator_type &alloc = allocator_type())
                : _alloc(alloc), _start(ft_nullptr), _end(ft_nullptr), _end_of_capacity(ft_nullptr) {}




            // fill constructor
            // 객체의 생성자호출하면 >  인스턴스화 된 객체가 val에 대입
            explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
                : _alloc(alloc), _start(ft_nullptr), _end(ft_nullptr), _end_of_capacity(ft_nullptr)
            {
                // value_type()이라는 생성자 호출! int
                // vector<int> a(5, 4)
                this->_start = this->_alloc.allocate(n);
                this->end = this->_start;
                this->_end_of_capacity = this->_start + n;
                while (n--)
                    this->_alloc.construct(this->_end++, val) // 각요소는 val의 복사본 (val 은 타입 아닌고?)
            }

            // range constructor
            template <typename InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
                    typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type* = ft_nullptr)
            : _alloc(alloc), _start(ft_nullptr), _end(ft_nullptr), _end_of_capacity(ft_nullptr)
            {
                difference_type n = ft::distance(first, last);
                //distance 생성
                this->_start = this->_alloc.allocate(n);
                this->end = this->_start;
                this->_end_of_capacity = this->_start + n;
                while (n--)
                    this->_alloc.construct(this->_end++, *first++); // ?
            }

            // copy constructor
            vector(const vector& other)
            // 이 따구로 접근을 할 수 있는 이유?
            : _alloc(other._alloc), _start(ft_nullptr), _end(ft_nullptr), _end_of_capacity(ft_nullptr)
            {
                size_type n = other.size();
                _start = _alloc.allocate(n);
                _end = _start;
                _end_of_capacity = _start + n;
                pointer p = other._start;
            }

            vector operator=(const vector& other)
            {
                if (this != &other) {
                    this->clear();  //구현
                    insert(_start, other.begin(), other.end());
                }
            }

            ~vector()
            {
                this->clear();
                _alloc.deallocate(_start, this->_end_of_capacity); // 구현

            }
		// ===================================================================================================

		// Iterators =========================================================================================

            iterator                        begin() { return (_start); }
            const iterator                  begin() const { return (_start); }
            iterator                        end() { return (_end); }
            const iterator                  end() const { return (_end); }
            reverse_iterator                rbegin() { return ( reverse_iterator(_end)); }
            const reverse_iterator          rbegin() const { return (reverse_iterator(_end)); }
            reverse_iterator                rend() { return (reverse_iterator(_start)); }
            const_reverse_iterator          rend() const { return (reverse_iterator(_start)); }

		// ===================================================================================================
        
		// Capacity ==========================================================================================

            bool                            empty() const { return (_start == _end); }
            size_type                       size() const { return (_end - _start); }
            size_type                       max_size() const { return (_alloc.max_size()); }
            // 이거 하면 뭐가 나옴
            size_type                       capcity() const { return (_end_of_capacity - _start); }

            void reserve(size_type n)
            {

            }

            void resize(sizse_type n, value_type val = value_type())
            {

            }
        // ===================================================================================================

		// Element Access ====================================================================================

        reference                           operator[](size_type n) { return (_start[n]); }
        const_reference                     operator[](size_type n) const { return (_start[n]); }
        reference                           at(sizt_type n )
        {

        }
        const_reference                     at(size_type n) const
        {

        }
        reference                           front() { return (*_start); }
        const_reference                     front() const { return (*_start); }
        reference                           back() { return (*(_end - 1)); }
        const_reference                     back() const { return (*(_end - 1)); }

		// ===================================================================================================

		// Modifiers =========================================================================================

        template<class InputIterator>
        void assign(InputIterator first, InputIterator last,
        typename ft::enable_if<!ft::is_inregral<InputIterator>::value, InputIterator>::type* = ft_nullptr)
        {

        }

        void assign(size_type n, const value_type& val)
        {

        }

        iterator insert(iterator position, const value_type& val)
        {

        }

        void insert(iterator positoin, size_type n, const value_type& val)
        {

        }

        template <class InputIterator>
        void insert(iterator positoin, InputIterator first, InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr)
        {

        }

        void push_back(const value_type& val)
        {

        }

        void pop_back()
        {

        }

        iterator erase(iterator pos)
        {

        }

        iterator erase(iterator first, iterator last)
        {

        }

        void swap(vector& other)
        {

        }

        void clear()
        {

        }
		// ======================================================================================================================

		// Allocator ============================================================================================================

        allocator_type get_allocator() const
        {

        }

		// ======================================================================================================================
        
    };
}

#endif