#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator.hpp"

namespace ft {

    // 5. 왜 두개 reverse_iterator 이랑 random_access_iterator랑 만드는 방식이 달라?
    //        iterator_traits       iterator
    //      class pointer 나누기 위함       iterator를 상속을 받아
    //  한단계가 더 필요한 이유는?

    // reverse_iterator random access iterator 범위를 통해 방향을 반전 시킨다
    // ?

    //param는 bidirectinal iterator >> random-access iterator 사용가능
    template <typename Iterator>
    class reverse_iterator
    {
        public:
        // Member types ======================================================================================

                // >> 포인터를 통해서 도 만들어진다 T*
            typedef Iterator iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category       iterator_category;
            typedef typename ft::iterator_traits<Iterator>::difference_type         difference_type;
            typedef typename ft::iterator_traits<Iterator>::value_type              value_type;
            typedef typename ft::iterator_traits<Iterator>::pointer                 pointer;
            typedef typename ft::iterator_traits<Iterator>::reference               reference;

		// ===================================================================================================

        protected:
            iterator_type _iter; // >> 위치값이다
        public:

		// Constructors ======================================================================================
        
            // default constructor
            reverse_iterator() : _iter() {}

            // initialization constructor
            explicit reverse_iterator (iterator_type it) : _iter(it) {}
            // >> 2. 뭘 위한 explicit인지?
            //형변환 제한을 둔다 원하는 대로 안들어오면 터트린다!
            //iterator_type 만을 만들기위한 생성자?

            // copy
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it) : _iter(rev_it.base()) {} 
            // base?
            // 3. 동작 방식이 궁금함 >> 복사생성자인가

            virtual ~reverse_iterator() {}

            // assignment
            template <typename Iter>
            reverse_iterator& operator=(const reverse_iterator<Iter>& rev_it) 
            {
                //this->_iter = rev_it.base(); // 가능
                //_iter에 const 대입 되겠지?
                //이게 아닌가?
                this->_iter = rev_it.base();
                return (*this);
            }

		// ===================================================================================================
            
		// Operator overloads ================================================================================

            // accesses the underlying adaptor
            iterator_type base() const // return base iterator
            {
                return (this->_iter);
            }

            //현재 위치에서 n만큼 차이나는 위치의 iterator 반환
            // 해당 기능들을 사용하기 위해서는 base iterator가 random_access_iterator여야한다.
            // 해당 기능을 vector에서 사용하므로 vector_iterator를 random_access_iterator

            reverse_iterator& operator+=(difference_type n)
            {
                _iter -= n;
                return (*this);
            }

            // 바로 위의 연산자 불러오기
            reverse_iterator operator+(difference_type n) const {
                reverse_iterator itr = (*this);
                return (itr += n);
            }

            reverse_iterator& operator-=(difference_type n)
            {
                //연산자 오버라이딩을 해버렸다
                _iter += n;
                return (*this);
            }

            reverse_iterator operator-(difference_type n) const {
                reverse_iterator itr = (*this);
                return (itr -= n);
            }

            // 6. 엥? 이거 더하기 뺴기 왜이럼

            //accesses an element by index
            //iterator가 현재 가리키는 요소에서 n개 위치에 있는 요소에 엑세스 한다.

            //7. 연산맞지?

            //reverse라서 -1하는 거
            //크기 벗어나면 터지는 게 맞?
            reference operator[](difference_type n) { return *(_iter - n - 1); }
            const reference operator[](difference_type n) const { return *(_iter - n - 1); }
            
            
            difference_type operator-(reverse_iterator other) { return (other._iter - _iter); }

            //  advances or decrements the iterator
            reverse_iterator& operator--() {
                ++_iter;
                return (*this);
            }

            reverse_iterator& operator--(int) {
                reverse_iterator itr = (*this);
                ++_iter;
                return (itr);
            }


            reverse_iterator& operator++() {
                --_iter;
                return (*this);
            }

            reverse_iterator& operator++(int) {
                reverse_iterator itr = (*this);
                --_iter;
                return (itr);
            }

            reference operator*() //dereference iterator
            {
                iterator_type tmp = this->_iter;
                //5. 뭐하는 거니? 이건 왜뻄?
                //end가 capacity 그 이상이라서
                //리버스라서!
                --tmp;
                return (*tmp);
            }

            // accesses the pointed-to-element
            const reference operator*() const //dereference iterator
            {
                iterator_type tmp = this->_iter;
                --tmp;
                return (*tmp);
            }

            pointer operator->() const //dereference iterator
            {
                //6. 주소가져오겠다
                return ( &(operator*()) );
            }

            //pointer operator->() const {
            //     iterator_type tmp = _iter;
            //     return  &(*(--tmp));
            // }
        
		// ===================================================================================================

    };

// operator overloads ====================================================================================

    template <typename iter>
    bool operator==(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return (lhs.base() == rhs.base()); }

    template <typename iter>
    bool operator!=(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return (lhs.base() != rhs.base()); }

    template <typename iter>
    bool operator<(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return (lhs.base() > rhs.base()); }

    template <typename iter>
    bool operator<=(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return (!(lhs > rhs)); }

    template <typename iter>
    bool operator>(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return (rhs < lhs); }

    template <typename iter>
    bool operator>=(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return !(lhs < rhs); }

    template <typename iter1, typename iter2>
    bool operator==(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs) { return (lhs.base() == rhs.base()); }

    template <typename iter1, typename iter2>
    bool operator!=(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs) { return (lhs.base() != rhs.base()); }

    template <typename iter1, typename iter2>
    bool operator<(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs) { return (lhs.base() > rhs.base()); }

    template <typename iter1, typename iter2>
    bool operator<=(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs) { return !(lhs > rhs); }

    template <typename iter1, typename iter2>
    bool operator>(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs) { return (rhs < lhs); }

    template <typename iter1, typename iter2>
    bool operator>=(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs) { return !(lhs < rhs); }

    template <typename iter>
    reverse_iterator<iter> operator+(typename reverse_iterator<iter>::difference_type n, const reverse_iterator<iter>& rev_it) { return (rev_it + n); }

    template <typename iter>
    typename reverse_iterator<iter>::difference_type operator-(const reverse_iterator<iter>& lhs, const reverse_iterator<iter>& rhs) { return (rhs - lhs); }

// ============================================================================================================

}   //namespace ft


#endif