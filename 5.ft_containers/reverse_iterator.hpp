#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator.hpp"

namespace ft {

    template <typename Iterator>
    class reverse_iterator
    {
        public:
        // Member types ======================================================================================

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
        
            reverse_iterator() : _iter() {}

            explicit reverse_iterator (iterator_type it) : _iter(it) {}

            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it) : _iter(rev_it.base()) {} 

            virtual ~reverse_iterator() {}

            template <typename Iter>
            reverse_iterator& operator=(const reverse_iterator<Iter>& rev_it) 
            {
                this->_iter = rev_it.base();
                return (*this);
            }

		// ===================================================================================================
            
		// Operator overloads ================================================================================

            iterator_type base() const
            {
                return (this->_iter);
            }
            
            reverse_iterator& operator+=(difference_type n)
            {
                _iter -= n;
                return (*this);
            }

            reverse_iterator operator+(difference_type n) const {
                reverse_iterator itr = (*this);
                return (itr += n);
            }

            reverse_iterator& operator-=(difference_type n)
            {
                _iter += n;
                return (*this);
            }

            reverse_iterator operator-(difference_type n) const {
                reverse_iterator itr = (*this);
                return (itr -= n);
            }

            reference operator[](difference_type n) { return *(_iter - n - 1); }
            const reference operator[](difference_type n) const { return *(_iter - n - 1); }
            
            
            difference_type operator-(reverse_iterator other) { return (other._iter - _iter); }

            reverse_iterator& operator--() {
                ++_iter;
                return (*this);
            }

            reverse_iterator operator--(int) {
                reverse_iterator itr = (*this);
                ++_iter;
                return (itr);
            }


            reverse_iterator& operator++() {
                --_iter;
                return (*this);
            }

            reverse_iterator operator++(int) {
                reverse_iterator itr = (*this);
                --_iter;
                return (itr);
            }

            reference operator*() //dereference iterator
            {
                iterator_type tmp = this->_iter;
                --tmp;
                return (*tmp);
            }

            const reference operator*() const //dereference iterator
            {
                iterator_type tmp = this->_iter;
                --tmp;
                return (*tmp);
            }

            pointer operator->() const //dereference iterator
            {
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