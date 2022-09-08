#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "algorithm.hpp"
#include "iterator_traits.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"


namespace ft {
    
    /* vector */
    template <typename T, class Allocator = std::allocator<T> >
    class vector {
        public:
            typedef T value_type;
            typedef Allocator allocator_type;

            // http://egloos.zum.com/sweeper/v/2966785
            // int를 할당하는 뿐 아니라 int 다음 그 전을 가르킬 공간 까지 할당을 해주기 위함!
            // int 만을 할당해서는 4바이트만 할당이 됨(실상은 2개의 포인터 + int 12 바이트! 가 필요)
            // 해당 쳄플릿 매개변수 T 타입의 컨테이너 allocator는 T타입이 아닌 다른 타입에 대한 allocate
            // 가 필요해 진다. >> (다른 타입이라함은 해당 컨테이너에서 요구되는 진정한 할당 타입!)
            // typedef typename allocator_type::template rebind<value_type>::other type_allocator;
            // 벡터의 템플릿이 이미 결정이 되어서 들어왔는데 그 안에 있는 것을 다른 유형으로 다시 생성을 한다

            // 노드 하나의 타입이 노드로써 set<int>

                // int
            // int   int
            // map < string, int >
            // >> string 으로 받아 온 것을 rebind Node <pair<string, int> 타입으로 받을 때 

            // string 보다 더 큰 (Node, pair) 타입을 이용해서 다른 형태의 allocator로 변환

            typedef	typename allocator_type::reference						reference;
            typedef	typename allocator_type::const_reference				const_reference;
            typedef	typename allocator_type::pointer						pointer;
            typedef	typename allocator_type::const_pointer					const_pointer;

            typedef ft::random_access_iterator<value_type> iterator;
            typedef ft::random_access_iterator<const value_type> const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

            typedef	typename allocator_type::size_type						size_type;
            typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;
            /* constructor & destructor */

            // default constructor
            explicit vector(const allocator_type& alloc = allocator_type())
            : _begin(ft::nil), _end(ft::nil), _cap(ft::nil), _alloc(alloc) {}
            
            // fill constructor
            explicit vector(size_type n, const value_type& value = value_type(),
            const allocator_type& alloc = allocator_type())
            : _alloc(alloc) {
                __init(n);
                __construct(n, value);
            }

            // range constructor
            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil)
            : _alloc(alloc) {
                size_type n = ft::distance(first, last);
                __init(n);
                __construct(n);
                std::copy(first, last, _begin); // begin에 first부터 last까지 복사를 해준다.
            }

            // copy constructor
            vector(const vector& v)
            : _alloc(v._alloc) {
                size_type n = v.size();
                __init(v.capacity()); // 메모리 크기 똑같이
                __construct(n);
                std::copy(v._begin, v._end, _begin);
            }

            // destructor
            ~vector(void) {
                if (_begin == ft::nil) { // allocator 조차 안되었을때
                    return;
                }
                size_type pre_capacity = capacity();
                __destruct(_begin); //여기까지 값없애 주고
                _alloc.deallocate(_begin, pre_capacity); // 할당 공간 삭제
            }

            // 연산자 =
            /* member function for util */
            vector& operator=(const vector& v) {
                if (this != &v) {
                    assign(v._begin, v._end); //assign
                }
                return *this;
            }

            /* iterators */

            // iterator로 typedef 된 random_access_iterator의 포인터 생성자 호출!
            iterator begin(void) {
                return iterator(_begin);
            }
            const_iterator begin(void) const {
                return const_iterator(_begin);
            }
            iterator end(void) {
                return iterator(_end);
            }
            const_iterator end(void) const {
                return const_iterator(_end);
            }
            reverse_iterator rbegin(void) {
                return reverse_iterator(end());
            }
            const_reverse_iterator rbegin(void) const {
                return const_reverse_iterator(end());
            }
            reverse_iterator rend(void) {
                return reverse_iterator(begin());
            }
            const_reverse_iterator rend(void) const {
                return const_reveres_iterator(begin());
            }

            /* element access */

            // 배열처럼 접근하여 인덱스에 대한 참조 반환
            reference operator[](size_type n) {
                return _begin[n];
            }

            const_reference operator[](size_type n) const {
                return _begin[n];
            }

            // 벡터의 n위치에 있는 요소에 대한 참조를 반환, n은 값이 아니라 위치!
            // 이 함수는 n이 벡터에서 유효한 요소의 범위 내에 있는지 여부를 자동으로 검사하고 그렇지 않으면 out_of_range 예외를 던진다.
		    // 이는 out_of_range 대해 검사하지 않는 멤버 연산자[]와 대조된다.
            reference at(size_type n) {
                if (n >= size()) {
                    throw std::out_of_range("index out of range");
                }
                return _begin[n];
            }

            const_reference at(size_type n) const {
                if (n >= size()) {
                    throw std::out_of_range("index out of range");
                }
                return _begin[n];
            }

            reference front(void) {
                return *_begin;
            }
            const_reference front(void) const {
                return *_begin;
            }
            reference back(void) {
                return *(_end - 1);
            }
            const_reference back(void) const {
                return *(_end - 1);
            }

            // ? 여기는 뭐 때문에 필요한걸까? 지워도 상관은 없을 거 같은데
            // string을 char*로 받을 때 data를 썻을 때 c_str(char *)은 const가 붙어서  data
            // const char * >> data
            // char * >> c_str

            // begin의 주소를 return
            // 배열에 대한 주소?

            // 실제 요소가 저장된 처음 주소를 반환
            T* data(void) throw() {
                return reinterpret_cast<T*>(_begin);
            }
            const T* data(void) const throw() {
                return reinterpret_cast<const T*>(_begin);
            }
            // iterator도 pointer이다. casting을 안전하게 하기 위함

            /* capacity */

            // pointer 차이를 size_type(size_t)로
            // ptr_diff 와 size_t 다르니까 이전에 캐스팅을 하였다.
            size_type   size(void)  const   { return (_end - _begin); }

            // 할당의 최대 사이즈를 _alloc에서 뽑아내기
            size_type   max_size()	const   { return _alloc.max_size(); }

            // n이 현재 컨테이너 크기보다 작으면, 그 이상의 요소를 제거하고 크기를 축소
			// n이 현재 컨테이너 크기보다 크면, n의 크기만큼 새로운 값을 삽입한다. value가 지정되면 새 요소가 value의 복사본으로 초기화 되고, 그렇지 않으면 값이 초기화된다.
            void resize(size_type n, value_type value = value_type()) {
                if (size() > n) {
                    size_type diff = size() - n;
                    __destruct(diff); // 객체 소멸
                }
                else if (size() < n) {
                    size_type diff = n - size();
                    if (capacity() < n) {
                        reserve(n);     // new_cap 크면 새 스토리지 할당 작으면 수행x,
                    }
                    __construct(diff, value); // 객체추가
                }
            }
            
            size_type	capacity()	const	{ return (_cap - _begin); } // 수용할 수 있는 공간

            bool empty(void) const { return _begin == _end; } // 비어있는지 확인

            // 벡터의 용량(재할당 없이 벡터가 보유할 수 있는 총 요소 수)보다 크거나 같은 값으로 늘 new_cap한다.
			// 현재 capacity() new_cap보다 크면 새 스토리지가 할당되고, 그렇지 않으면 함수가 아무 작업도 수행하지 않는다.
            // capacity를 늘려줘
            void reserve(size_type n) {
                if (n <= capacity()) { // n <= size()
                    return;
                }
                if (n < capacity() * 2) {
                    n = capacity() * 2;
                }
                size_type pre_size = size();
                size_type pre_capacity = capacity();
                pointer begin = _alloc.allocate(n); // 공간 할당

                // https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=hiko_seijuro&logNo=110008273000
                // https://social.msdn.microsoft.com/Forums/vstudio/en-US/e0bd2dd9-173d-4894-b39a-b5b08e96d70e/difference-between-stdcopy-and-stduninitializedcopy?forum=vcgeneral
                
                // std::copy는 operator=를 사용하여 대상 범위의 기존 개체를 덮어씁니다.
                // std::uninitialized_copy는 new 배치를 사용하여 대상 범위에 새 개체를 만듭니다. (개체가 존재하지 않음)
                // 대상 범위에 기존 개체가 있으면 메모리가 손상될 수 있습니다.

                // 메모리 할당을 객체 생성에서 분리할 수 있게 하는 STL의 저수준 구성요소들 중 하나이다.
                // 개체를 생성해서 begin으로 가리키는 듯?
                // construct까지 해주는 듯?
                

                // int float 메모리할당이나 new이나

                // custom 으로 animal 생성자로 >> brain(메모리 할당하는 공간)
                // 메모리 할당만 받아서 copy를 해야 brain 까지

                // 객체가 없었던 공간에 생성자를 호출해서 할당해놓은 공간에 copy를 한다.
                std::uninitialized_copy(_begin, _end, begin);

                __destruct(_begin);
                _alloc.deallocate(_begin, pre_capacity);
                _begin = begin;
                _end = _begin + pre_size;
                _cap = _begin + n;
            }

            /* modifiers */
            // 벡터에 새 내용을 할당하고 현재 내용을 교체하고 그에 따라 크기를 수정한다.
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last,
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil) {
                size_type n = ft::distance(first, last);
                if (capacity() < n) {
                    reserve(n);
                }
                // _begin 복사한 원소들을 저장할 곳의 시작점을 나타내는 반복자
                std::copy(first, last, _begin);
                _end = _begin + n;
            }

            // assigin, insert, push_back
            // stl과 다르다.
            void assign(size_type n, const value_type& value) {
                if (capacity() < n) {
                    reserve(n);
                }
                // 배열 초기화
                // 변경하려는 원소의 범위 시작주소, 변경하려는 원소 갯수, 변경 값
                std::fill_n(_begin, n, value);
                _end = _begin + n;
            }

            // 벡터의 뒤에 새로운 element를 추가한다.
            // 늘어난 벡터의 크기가 capacity를 넘어갈 경우, 이전 capacity * 2의 크기로 늘어남 (reserve에서)
            void push_back(const value_type& value) {
                size_type n = size() + 1;
                if (capacity() < n) {
                    reserve(n);
                }
                __construct(1); // 객체 추가
                *(_end - 1) = value;
            }

            void pop_back(void) {
                __destruct(1); // 객체 소멸
            }

            // insert 추가하기! single, fill, range
            iterator insert(iterator position, const value_type& value) {
                difference_type diff = position - begin();
                if (capacity() < size() + 1) {
                    reserve(size() + 1);
                }
                pointer ptr = _begin + diff;
                __construct(1);

                // https://runebook.dev/ko/docs/cpp/algorithm/copy_backward
                // [first, last) 정의 된 범위에서 d_last 로 끝나는 다른 범위로 요소를 복사합니다 . 요소는 역순으로 복사되지만 (마지막 요소가 먼저 복사 됨) 상대 순서는 유지됩니다.
                // 뒤로 미는 구나 뒤에서 부터 복사해야하니까 backward
                std::copy_backward(ptr, _end - 1, _end);
                *ptr = value;
                return iterator(ptr);
            }
            
            void insert(iterator position, size_type n, const value_type& value) {
                difference_type diff = position - begin();
                if (capacity() < size() + n) {
                    reserve(size() + n);
                }
                pointer ptr = _begin + diff;
                __construct(n);
                std::copy_backward(ptr, _end - n, _end);
                for (size_type i = 0 ; i < n ; i++) {
                    ptr[i] = value;
                }
            }
            
            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last,
            typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil) {
                difference_type n = ft::distance(first, last);
                difference_type diff = position - begin();
                if (capacity() < size() + n) {
                    reserve(size() + n);
                }
                pointer ptr = _begin + diff;
                __construct(n);
                std::copy_backward(ptr, _end - n, _end);
                for (InputIterator i = first ; i != last ; i++, ptr++) {
                    *ptr = *i;
                }
            }

            iterator erase(iterator position) {
                difference_type diff = position - begin();
                pointer ptr = _begin + diff;
                // 이런식으로 빼고 더하는 이유는? 포인터 위치 찾아줄려고 하는 구나(differenc_type으로 pointer 연산하기 위해서)
                // ptr이 가리키게 하는 것을 ptr + 1 뭐 이런식
                std::copy(ptr + 1, _end, ptr);
                __destruct(1);
                return iterator(ptr);
            }

            iterator erase(iterator first, iterator last) {
                difference_type n = ft::distance(first, last);
                std::copy(last, end(), first);
                __destruct(n);
                return first;
            } 

            void swap(vector& v) {
                std::swap(_begin, v._begin);
                std::swap(_end, v._end);
                std::swap(_cap, v._cap);
                std::swap(_alloc, v._alloc);
            }

            void clear(void) {
                __destruct(_begin);
            }

            /* allocator */
            // 벡터와 연결된 할당자 객체의 복사본을 반환한다.
		    // 진베 왈 : 외부에서 만들어 놓은 하나(이상)의 인자를 이미 만들어놓은 벡터의 allocator 안에 넣기 위함?
            // allocator의 type을 이용하기 위해서
            allocator_type get_allocator(void) const {
                return _alloc;
            }

            private:
                pointer _begin;
                pointer _end;
                pointer _cap;
                allocator_type _alloc;

            /* initialize memory & iterating pointer */
            void __init(size_type n) {
                if (n > max_size()) {
                    throw std::length_error("allocation size too big");
                }
                _begin = _alloc.allocate(n); // 공간만 할당
                _end = _begin; 
                _cap = _begin + n;
            }

            /* construct with specific value */
            void __construct(size_type n, T value) {
                for ( ; n > 0 ; _end++, n--) {
                    _alloc.construct(_end); // 객체 추가
                    *_end = value; // 초기화
                }
            }

            /* construct without value */
            void __construct(size_type n) {
                for ( ; n > 0 ; _end++, n--) {
                    _alloc.construct(_end);
                }
            }

            /* destruct with size from end */
            void __destruct(size_type n) {
                for ( ; n > 0 && _end-- ; n--) {
                    _alloc.destroy(_end); // 객체 소멸 .. 공간은 남아있음
                }
            }

            /* destruct from end to pointer */
            void __destruct(pointer until) {
                for ( ; _end != until && _end-- ; ) {
                    _alloc.destroy(_end);
                }
            }
    };

    /* relational operators */
    // 같은거 확인 위해 equal
    template <typename T, class Allocator>
    bool operator==(const ft::vector<T, Allocator>& x,
                    const ft::vector<T, Allocator>& y) {
    return x.size() == y.size() &&
            ft::equal(x.begin(), x.end(), y.begin());
    }

    template <typename T, class Allocator>
    bool operator!=(const ft::vector<T, Allocator>& x,
                    const ft::vector<T, Allocator>& y) {
    return !(x == y);
    }

    //  다른거 찾으면 false 뽑아내기위해서 lexico
    template <typename T, class Allocator>
    bool operator<(const ft::vector<T, Allocator>& x,
                const ft::vector<T, Allocator>& y) {
    return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    }

    template <typename T, class Allocator>
    bool operator<=(const ft::vector<T, Allocator>& x,
                    const ft::vector<T, Allocator>& y) {
    return x == y || x < y;
    }

    template <typename T, class Allocator>
    bool operator>(const ft::vector<T, Allocator>& x,
                const ft::vector<T, Allocator>& y) {
    return !(x <= y);
    }

    template <typename T, class Allocator>
    bool operator>=(const ft::vector<T, Allocator>& x,
                    const ft::vector<T, Allocator>& y) {
    return x == y || x > y;
    }

    /* non member function for util */
    // 벡터 두개를 바꾸기 위함
    // swap (x, y) 를 호출 하면 x.swap(y)가 호출이 된다.
    template <typename T, class Allocator>
    void swap(ft::vector<T, Allocator>& x,
            ft::vector<T, Allocator>& y) {
        x.swap(y);
    }
} // namespace ft

#endif 
