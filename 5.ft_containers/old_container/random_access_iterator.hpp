#ifndef RANDOM_ACCESS_ITERATOR
# define RANDOM_ACCESS_ITERATOR

#include "iterator.hpp"
#include "utils.hpp"

// ->, *, ++, --, [], +, -, +=, -=, <, <=, >=, >=

// 랜덤 액세스 iterator로 사용하기 위함
// 요소에 접근하는데 사용할 수 있는 iterator
// 그들이 가리키는 요소에 상대적인 임의의 오프셋 위치에서, 포인터와 동일한 기능 제공

// T >> iterator가 가리키는 요소의 유형

namespace ft {
    template <typename T>
                                        //iterator      iterator_category, value_type
    class random_access_iterator : public ft::iterator<random_access_iterator_tag, T> {
        public:
		// Member types ======================================================================================

            // ft::iterator<random_access_iterator_tag, T>상속받은 친구들 ::(이것으로 접근) 내부 변수 이름 바꿔주기
            typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category iterator_categoty;
            typedef typename ft::iterator<random_access_iterator_tag, T>::pointer pointer;
            typedef typename ft::iterator<random_access_iterator_tag, T>::reference reference;
            typedef typename ft::iterator<random_access_iterator_tag, T>::value_type value_type;
            typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type difference_type;
            // Distance (= ptrdiff_t) >> difference_type
            // ptrdiff_t 두 포인터를 뺀 결과의 부호 있는 정수 유형

		// ===================================================================================================

        // random access iterator
        // pointer base로 만들기 위함! >> iterator는 포인터의 확장판! type을 가지고 있다
        private:
            pointer _ptr;

        public:
		// Constructors ======================================================================================

            random_access_iterator() : _ptr(ft_nullptr) {}
            // 1. ref._ptr로 받는 이유는 private 아닌가요?
            random_access_iterator(const random_access_iterator& ref) : _ptr(ref._ptr) {}

            random_access_iterator(pointer ptr) : _ptr(ptr) {}

            virtual ~random_access_iterator() {}

            random_access_iterator& operator=(const random_access_iterator& ref) {
                if (this != &ref)
                    this->_ptr = ref._ptr;
                return (*this);
            }

		// ===================================================================================================

		// Operator overloads ================================================================================

        pointer base() const {
            return (this->_ptr);
        }

        //2. _ptr을 건드는거니까 (두 포인터를 뺀 결과의 부호 있는 정수 유형) difference_type으로 연산을 한다?!
        random_access_iterator& operator+=(difference_type n) {
            _ptr += n;
            return (*this);
        }

        random_access_iterator operator+(difference_type n) const {
            random_access_iterator itr = (*this);
            return (itr += n);
        }

        random_access_iterator& operator-=(difference_type n) {
            _ptr -= n;
            return (*this);
        }

        random_access_iterator operator-(difference_type n) const {
            random_access_iterator itr = (*this);
            return (itr -= n);
        }

        reference operator[](difference_type n) {
            return (_ptr[n]);
        }

        const reference operator[](difference_type n) const {
            return (_ptr[n]);
        }
        
        template<typename U>
        random_access_iterator& operator=(random_access_iterator<U> other) {
            this->_ptr = other.base();
            return (*this);
        }

        random_access_iterator& operator--() {
            --_ptr;
            return (*this);
        }

        random_access_iterator operator--(int) {
            random_access_iterator itr = (*this);
            --_ptr;
            return (itr);
        }

        random_access_iterator& operator++() {
            ++_ptr;
            return (*this);
        }

        random_access_iterator operator++(int) {
            random_access_iterator itr = (*this);
            ++_ptr;
            return (itr);
        }
        
        reference   operator*() { return (*_ptr); } //value
        
        const reference operator*() const { return (*_ptr); }

        pointer     operator->() { return (_ptr); } //address

        //overloading type casting.. 변환연산자!
        operator random_access_iterator<const T> () const { return (random_access_iterator<const T>(this->_ptr)); }
        // ===================================================================================================
    };

    // operator overloads ====================================================================================

    // +, - 구현이 다른 이유? // 반환값이 달라서
    // +는 왜 하나 밖에?
    //3. 위 의 +랑 다른건 알겠는데 뭐가 다름?(다른 iterator ?)

    //4. n의 크기, iterator하나
    //T에 따라서 뭔가 달라지는 거 같은데(value type?)
    template<typename T>
    random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& iterator) {
            random_access_iterator<T> itr = iterator;
            return (itr + n);
    }

    //두 iterator의 차이의 크기! 반환
    //같은 유형 iter -
    template<typename iter>
    typename ft::random_access_iterator<iter>::difference_type operator-(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) {
        return (lhs.base() - rhs.base());
    }

    //다른 유형 iter -
    template<typename iter1, typename iter2>
    typename ft::random_access_iterator<iter1>::difference_type operator-(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) {
        return (lhs.base() - rhs.base());
    }
    
    //same type operator
    template<typename iter>
    bool operator==(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (lhs.base() == rhs.base()); }

    template<typename iter>
    bool operator!=(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (lhs.base() != rhs.base()); }

    template<typename iter>
    bool operator<(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (lhs.base() < rhs.base()); }

    template<typename iter>
    bool operator>(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (lhs.base() > rhs.base()); }

    template<typename iter>
    bool operator<=(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (lhs.base() <= rhs.base()); }

    template<typename iter>
    bool operator>=(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (lhs.base() >= rhs.base()); }

    //different type operator
    template<typename iter1, typename iter2>
    bool operator==(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (lhs.base() == rhs.base()); }

    template<typename iter1, typename iter2>
    bool operator!=(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (lhs.base() != rhs.base()); }

    template<typename iter1, typename iter2>
    bool operator<(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (lhs.base() < rhs.base()); }

    template<typename iter1, typename iter2>
    bool operator>(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (lhs.base() > rhs.base()); }

    template<typename iter1, typename iter2>
    bool operator<=(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (lhs.base() <= rhs.base()); }

    template<typename iter1, typename iter2>
    bool operator>=(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (lhs.base() >= rhs.base()); }

	// =======================================================================================================
    
}   // namespace ft

#endif