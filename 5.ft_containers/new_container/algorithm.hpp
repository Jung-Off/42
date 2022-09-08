#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <cstdint>
#include "iterator_traits.hpp"

// https://en.cppreference.com/w/cpp/algorithm/equal

namespace ft {

// equal ====================================================
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2) {
        for ( ; first1 != last1 ; first1++, first2++) {
            if (!(*first1 == *first2)) {
                return false;
            }
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2, BinaryPredicate pred) {
        for ( ; first1 != last1 ; first1++, first2++) {
            if (!pred(*first1, *first2)) {
                return false;
            }
        }
        return true;
    }

// ============================================================================

// lexicographical compare ====================================================

// https://junstar92.tistory.com/329

// 불변형 순차 알고리즘이란 주어진 범위에서 원소를 검색하거나 두 범위를 서로 비교하는 함수

// 주어진 범위의 비교를 할 때, equal(), mismatch(), lexico... 이 알고리즘들은 비교할 범위가 속한
// 컨테이너가 달라도 적용가능,, vector에 있는 원소와 list를 비교할 수 있다. 일반적으로 비교 알고리즘은 순차 컨테이너에
// 적용할 때 성능이 가장 뛰어나면, 각 컬렉션에서 동일한 위치에 있는 값끼리 비교하는 방식으로 실행

// 첫 번째로 일치하지 않는 양쪽 범위의 원소중에서 첫 번째 범위의 원소가 두번째 범위의 원소보다 작거나, 첫 번째 범위의 원소수가 두번째 원소수보다
// 적으면서 첫 번째 범위의 원소가 모두 두번째 범위의 앞부분과 일치하면 true 리턴 lexico... 이름이 붙은 이유는 문자열을 나열하는 방식이 사전과 비슷
// 이 알고리즘은 모든 타입의 객체를 다룰 수 있도록 규칙 확장

// 타입이 다른 컨테이너의 원소 두개 비교할 경우 equal,, lexico...보단 ==, < 사용하는 것이 좋음
// 표준 알고리즘은 서로 타입이 다른 컨테이너의 부분 범위나 C스타일의 배열을 비교하는데 적합

// lexicographical_compare 첫번째 컨테이너가 두번째와 사전순으로 같거나
// 두번째보다 앞에 오면 true, 그렇지 않으면 false를 반환.
// 첫 번째 범위 [first1, last1) 가 사전 식 인지 확인합니다.less두 번째 범위보다 [first2, last2) .
// 1) operator< 사용하여 요소를 비교 합니다.
// 3) 주어진 이진 비교 함수 comp 를 사용하여 요소를 비교합니다 .


// https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2) {
        for ( ; first2 != last2 ; first1++, first2++) {
            if (first1 == last1 || *first1 < *first2) {
                return true;
            }
            if (*first1 > *first2) {
                return false;
            }
        }
        return false;
    }

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                Compare comp) {
        for ( ; first2 != last2 ; first1++, first2++) {
            if (first1 == last1 || comp(*first1, *first2)) {
                return true;
            }
            if (comp(*first2, *first1)) {
                return false;
            }
        }
        return false;
    }

// ============================================================================

    /* distance */
    // iterator 를 std를 사용하면 distance를 <iterator> 이런식으로 해서 불러올 수 있는 거 같은데
    // 이게 아니라면
    // iterator 를 ft로 구현을 하면 distance를 구현해야한다.
    template < typename InputIt >
	typename ft::iterator_traits<InputIt>::difference_type	distance(InputIt first, InputIt last)
	{
		typename ft::iterator_traits<InputIt>::difference_type	dist = 0;
		while (first != last){
			++first;
			++dist;
		}
		return dist;
	}

} // namespace ft

#endif