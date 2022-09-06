#ifndef UTILS_HPP
# define UTILS_HPP

#include "iterator.hpp"

// enable_if ==================================================================

// cond 부분에 우리가 확인하고 싶은 조건을 전달한다.만일 cond가 참으로 연산이 된다면
// enable_if:type의 타입이 T가 되고 cond가 거짓이라면 enable_if에 type이 존재하지
// 않게 된다.

// 어떤함수의 인자 T가 정수 일때만 오버로딩을 하고 싶다
// std::enable_if<std::is_integral<T>::value>::type
// cond 에 std::integral<T>::value 전달한 것!

namespace ft {

	template <bool cond, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> {
			typedef T type;
	};

// ============================================================================

// ft_nullptr =================================================================

	static class nullptr_t {
		
        private:
			void operator&() const;

		public:
			template <class T>
			operator T*() const {
				return 0;
			}

			template <class T, class C>
			operator T C::*() const {
				return 0;
			}
	} ft_nullptr = {};

// ============================================================================

// is_integral ================================================================

	template <bool is_integral, typename T>
	struct is_integral_base {
		typedef T type;
		const static bool value = is_integral;
	};

	template<typename>
	struct is_integral : public is_integral_base<false, void> {};
	
	//특수화
	template<>
	struct is_integral<bool> : public is_integral_base<true, bool> {};

	template<>
	struct is_integral<char> : public is_integral_base<true, char> {};

	template<>
	struct is_integral<signed char> : public is_integral_base<true, signed char> {};

	template<>
	struct is_integral<unsigned char> : public is_integral_base<true, unsigned char> {};

	template<>
	struct is_integral<short> : public is_integral_base<true, short> {};

	template<>
	struct is_integral<unsigned short> : public is_integral_base<true, unsigned short> {};

	template<>
	struct is_integral<int> : public is_integral_base<true, int> {};

	template<>
	struct is_integral<unsigned int> : public is_integral_base<true, unsigned int> {};

	template<>
	struct is_integral<long> : public is_integral_base<true, long> {};

	template<>
	struct is_integral<unsigned long> : public is_integral_base<true, unsigned long> {};

	template<>
	struct is_integral<long long> : public is_integral_base<true, long long> {};

	template<>
	struct is_integral<unsigned long long> : public is_integral_base<true, unsigned long long> {};

	template<>
	struct is_integral<wchar_t> : public is_integral_base<true, wchar_t> {};

	template<>
	struct is_integral<char16_t> : public is_integral_base<true, char16_t> {};

	template<>
	struct is_integral<char32_t> : public is_integral_base<true, char32_t> {};

// ============================================================================

// distance ===================================================================

	
	template <typename InputIt>
	typename ft::iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last)
	{
		typename ft::iterator_traits<InputIt>::difference_type n = 0;

		// 포인터의 이터레이터 화! 를 위함!
		// 포인터가 들어올지 이터레이터가 들어올지 모르는 상황에서 포인터를 이터레이터 처럼 사용하기 위해서
		// 저거에 들어가면 이터레이터가 가지고 있는 typename들이 포인터에도 똑같이 생성!
		// iterator_traits를 통해 포인터의 이터레이터화!

		while (first != last)
		{
			++first;
			++n;
		}
		return n;
	}

// lexicographical compare ====================================================

// https://junstar92.tistory.com/329

// 3. lexicographical_compare을 쓰는이유?


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

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while(first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while(first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
// ============================================================================

// is_input_iter ==============================================================

// 2. 필요한 이유는?
	
// ============================================================================


}
#endif
