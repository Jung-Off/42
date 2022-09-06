#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

// https://cplusplus.com/reference/iterator/reverse_iterator/?kw=reverse_iterator
// reverese_iterator =================================================================

    template <class Iterator>
    class reverse_iterator {

        public:
                // random access iterator 기반으로 만들어지기 떄문에! Iterator를 받아온다
        typedef Iterator itertor_type;
        typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
        typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
        typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
        typedef typename ft::iterator_traits<iterator_type>::reference reference;
        typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
 
// constructor & destructor =================================================================

        // default constructor << random_access_iterator
        reverse_iterator(void) : iterator(iterator_type()) {}

        // fill constructor
        explicit reverse_iterator(iterator_type i) : iterator(i) {}
        // >> 2. 뭘 위한 explicit인지?
        // 형변환 제한을 둔다 원하는 대로 안들어오면 터트린다!
        // 암시적 형변환을 안되게!
        // random_access_iterator 만 받아오게 끔! (iterator_type 만을 만들기위한 생성자?)

        // copy constructor
        template <class Other>
        reverse_iterator(const reverse_iterator<Other>& i) : iterator(i.base()) {}

        // destructor
        ~reverse_iterator(void) {}

// member function for util =================================================================

        // 대입 연산자
        template <class Other>
        reverse_iterator& operator=(const reverse_iterator<Other>& i) {
            iterator = i.base();
            return *this;
        }

        // getter
        iterator_type base(void) const { return iterator; }

        //5. 뭐하는 거니? 이건 왜뻄?
        // end가 capacity 그 이상이라서
        // 리버스라서!
        // 가리키고 있는 것과 끄집어 내야하는 값이 달라서
        reference operator*(void) const {
            iterator_type tmp = iterator;
            return *--tmp;
        }

        // ? 이거 맞아 어떻게 동작?
        reference operator[](difference_type n) const {
            return *(*this + n);
        }
        // *this -> 이객체  ( (*this = )it + n) 으로 주소 연산을 한거고 여기서 *로 접근을 하면 여기의 값에 접근한다.

        // 위의 것의 주소를 주소를 가져오겠다
        pointer operator->(void) const { return &operator*(); }

// increment & decrement =================================================================

        reverse_iterator& operator++(void) {
            --iterator;
            return *this;
        }

        reverse_iterator& operator--(void) {
            ++iterator;
            return *this;
        }

        reverse_iterator operator++(int) {
            reverse_iterator tmp(*this);
            --iterator;
            return tmp;
        }

        reverse_iterator operator--(int) {
            reverse_iterator tmp(*this);
            ++iterator;
            return tmp;
        }

// arithmetic operators =================================================================
        
        //현재 위치에서 n만큼 차이나는 위치의 iterator 반환
        // 해당 기능들을 사용하기 위해서는 base iterator가 random_access_iterator여야한다.
        // 해당 기능을 vector에서 사용하므로 vector_iterator를 random_access_iterator

        reverse_iterator operator+(difference_type n) const {
            return reverse_iterator(iterator - n);
        }

        reverse_iterator operator-(difference_type n) const {
            return reverse_iterator(iterator + n);
        }

        reverse_iterator& operator+=(difference_type n) {
            iterator -= n;
            return *this;
        }

        reverse_iterator& operator-=(difference_type n) {
            iterator += n;
            return *this;

        //accesses an element by index
        //iterator가 현재 가리키는 요소에서 n개 위치에 있는 요소에 엑세스 한다.
        
        }
        private:
            Iterator iterator; // >> 위치값이다 
    };

// special case of arithmetic operators =================================================================

    // n + i;
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
                                        const reverse_iterator<Iterator>& i) {
    return reverse_iterator<Iterator>(i.base() - n);
    }

    // 두개의 이터레이터 차이
    template <class Iterator1, class Iterator2>
    typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& x,
                                                                    const reverse_iterator<Iterator2>& y) {
    return y.base() - x.base();
    }

// relational operators =================================================================

    template <class Iterator1, class Iterator2>
    bool operator==(const reverse_iterator<Iterator1>& x,
                    const reverse_iterator<Iterator2>& y) {
    return x.base() == y.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator!=(const reverse_iterator<Iterator1>& x,
                    const reverse_iterator<Iterator2>& y) {
    return x.base() != y.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator<(const reverse_iterator<Iterator1>& x,
                const reverse_iterator<Iterator2>& y) {
    return x.base() > y.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator<=(const reverse_iterator<Iterator1>& x,
                    const reverse_iterator<Iterator2>& y) {
    return x.base() >= y.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator>(const reverse_iterator<Iterator1>& x,
                const reverse_iterator<Iterator2>& y) {
    return x.base() < y.base();
    }

    template <class Iterator1, class Iterator2>
    bool operator>=(const reverse_iterator<Iterator1>& x,
                    const reverse_iterator<Iterator2>& y) {
    return x.base() <= y.base();
    }
}
#endif