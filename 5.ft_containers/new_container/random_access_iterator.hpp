#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define  RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "type_traits.hpp"

// ->, *, ++, --, [], +, -, +=, -=, <, <=, >=, >=

// 랜덤 액세스 iterator로 사용하기 위함
// 요소에 접근하는데 사용할 수 있는 iterator
// 그들이 가리키는 요소에 상대적인 임의의 오프셋 위치에서, 포인터와 동일한 기능 제공

// T >> iterator가 가리키는 요소의 유형
// vector, list든 random_access_iterator를 기반으로 해서 vector, list 이터레이터가 따로 정의

namespace ft {

// random_access_iterator =================================================================
                                        //iterator      iterator_category, value_type
template <typename T>
class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {

    // https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator

    public:
        typedef T* iterator_type;       
        
        // 왜 T* 로 썻는지?
        // T로 되어있으면 iterator_traits가 > 특수화 되지 않아서 리턴값이 const로 나오지 않고 일반화 된 것으로 나온다
        // 우리가 의도한 것을 찾을 수 없다!
        // T*로 되어있으면 int가 들어가면 int* 로 넣어서 iterator_traits에서 특수화 된 것으로 찾게 끔 하여서
        // 그 안에서 자신의 타입을 찾을 수 있게 끔 만들어 놓았다!
        
        // iterator_type을 사용하기 위함이다 const

        typedef typename ft::iterator_traits<iterator_type>::value_type         value_type;
        typedef typename ft::iterator_traits<iterator_type>::difference_type    difference_type;
        typedef typename ft::iterator_traits<iterator_type>::pointer            pointer;
        typedef typename ft::iterator_traits<iterator_type>::reference          reference;
        typedef typename ft::iterator_traits<iterator_type>::iterator_category  iterator_category;

        // Distance (= ptrdiff_t) >> difference_type
        // ptrdiff_t 두 포인터를 뺀 결과의 부호 있는 정수 유형

// constructor & destructor =================================================================

        // default constructor
        random_access_iterator(void): _i(ft::nil) {}

        // fill constructor (pointer fill)
        random_access_iterator(T* pointer) : _i(pointer) {} 

        // type이 U인것 copy
        template<typename U>
        random_access_iterator(const random_access_iterator<U>& i) : _i(i.base()) {}

        //destructor
        ~random_access_iterator(void) {}

// member function for util =================================================================

        // 타입이 U인 것을 대입연산자 // i 와 this 의 추가 여부
        template <typename U>
        random_access_iterator& operator=(const random_access_iterator<U>& i)
        {
            _i = i.base();
            return *this;
        }

        // getter
        iterator_type base(void) const { return _i; }

        // address  get _i가 pointer니까
        pointer operator->(void) const { return _i; }

        // base와 operator->와 다른점
        // 오퍼레이터를 오버라이딩해야되서
        // 같은 기능이지만 두개를 구현

        // value get
        reference operator*(void) const { return *_i; }

        // [] 접근
        reference operator[](difference_type n) const { return _i[n]; }
        // 얼마나 떨어져 있는지를 알게 하는 type이다
        // difference_type이란 주소값에서 얼마나 멀어졌는지 시작 주소에서 몇번째! 

// increment & decrement =================================================================

        // i++;
        random_access_iterator& operator++(void) {
            ++_i;
            return *this;
        }
        
        // i--;
        random_access_iterator& operator--(void) {
            --_i;
            return *this;
        }

        // ++i;
        random_access_iterator operator++(int) {
            random_access_iterator tmp(*this);
            ++_i;
            return tmp;
        }

        // --i;
        random_access_iterator operator--(int) {
            random_access_iterator tmp(*this);
            --_i;
            return tmp;
        }

// arithmetic operators =================================================================

        // fill constructor로서 생성 i + n
        random_access_iterator operator+(difference_type n) const {
            return random_access_iterator(_i + n);
        }

        // i - n
        random_access_iterator operator-(difference_type n) const {
            return random_access_iterator(_i - n);
        }

        // add and this return
        // 2. _ptr을 건드는거니까 (두 포인터를 뺀 결과의 부호 있는 정수 유형) difference_type으로 연산을 한다
        // i += n
        random_access_iterator& operator+=(difference_type n) {
            _i += n;
            return *this;
        }

        // i -= n
        random_access_iterator& operator-=(difference_type n) {
            _i -= n;
            return *this;
        }
        // random access iterator

        // pointer base로 만들기 위함! >> iterator는 포인터의 확장판! type을 가지고 있다
        private:
            pointer _i;
    };

// special case of arithmetic operators =================================================================

    // +, - 구현이 다른 이유? // 반환값이 달라서

    // T가 다른것!
    // 4. n의 크기, iterator하나

    // 순서가 다르다!!!! n + i
    template <typename T>
    random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n,
                                        const random_access_iterator<T>& i) {
        return random_access_iterator<T>(i.base() + n);
    }

    // T1, T2가 다른 것 연산
    // 이터레이터 두개의 차이,  주소값의 사이 차이 
    // reference 5번째!
    template<typename T1, typename T2>
    typename random_access_iterator<T1>::difference_type operator-(const random_access_iterator<T1>& x,
                                                                    const random_access_iterator<T2>& y) {
        return  x.base() - y.base();
    }

// relational operators =================================================================

    // 두 랜덤엑세스 이터레이터 비교하는 연산자 오버로딩
    // 두개가 같은지
    // 주소값 비교하기? begin != end 이런거에서 쓰기 위함
    template <typename T1, typename T2>
    bool operator==(const random_access_iterator<T1>& x, const random_access_iterator<T2>& y) {
        return x.base() == y.base();
    }

    // 두개가 다른지
    template <typename T1, typename T2>
    bool operator!=(const random_access_iterator<T1>& x, const random_access_iterator<T2>& y) {
        return x.base() != y.base();
    }

    // 오른쪽이 큰지
    template <typename T1, typename T2>
    bool operator<(const random_access_iterator<T1>& x, const random_access_iterator<T2>& y) {
        return x.base() < y.base();
    }

    // 오른쪽이 크거나 같은지
    template <typename T1, typename T2>
    bool operator<=(const random_access_iterator<T1>& x, const random_access_iterator<T2>& y) {
        return x.base() <= y.base();
    }

    // 왼쪽이 큰지
    template <typename T1, typename T2>
    bool operator>(const random_access_iterator<T1>& x, const random_access_iterator<T2>& y) {
        return x.base() > y.base();
    }

    // 왼쪽이 크거나 같은지
    template <typename T1, typename T2>
    bool operator>=(const random_access_iterator<T1>& x, const random_access_iterator<T2>& y) {
        return x.base() >= y.base();
    }

} // namespace ft

#endif