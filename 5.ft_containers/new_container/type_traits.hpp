#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

#include <cstdint> // 아래 타입들 불러오는데!

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
			void operator&() const; //주소 참조 x 하기 위해서

		public:
			template <class T>
			operator T*() const {
				return 0;
			}

			template <class T, class C>
			operator T C::*() const {
				return 0;
			}
	} nil = {};

// ============================================================================

/* integral_constant */
template <typename T, T v>
struct integral_constant {
  typedef T value_type;				// 밖에서 template을 써줘서 구체적으로 <, > 이렇게 안써줘도 template에 맞게 false, true_type을 찾아가는 듯?
  typedef integral_constant type;	// 이거 어디에서 쓰나요? >> 결정된 타입이 나온다 컴파일시 타입을 알아낼수 있다
									// true_type이냐 false_type이냐를 integral_constant으로 알 수 있는걸 type으로 
									// 다시 이름 붙인 것!
									// integral_constant가 true_type, false_type이런식으로 들어가
									// ex)	integral_constant<bool, true> 
									//		integral_constant<bool, false> 이게 type이다! 
  static const value_type value = v;
};

typedef integral_constant<bool, true> true_type;

typedef integral_constant<bool, false> false_type;

/* remove_cv */
template <typename T>
struct remove_cv { typedef T type; };

template <typename T>
struct remove_cv<const T> { typedef T type; };

template <typename T>
struct remove_cv<volatile T> { typedef T type; };

template <typename T>
struct remove_cv<const volatile T> { typedef T type; };

/* is_integral_base */
	template <typename>
	struct is_integral_base : public false_type {};

	template <>
	struct is_integral_base<bool> : public true_type {};

	template <>
	struct is_integral_base<char> : public true_type {};

	template <>
	struct is_integral_base<char16_t> : public true_type {};

	template <>
	struct is_integral_base<char32_t> : public true_type {};

	template <>
	struct is_integral_base<wchar_t> : public true_type {};

	template <>
	struct is_integral_base<signed char> : public true_type {};

	template <>
	struct is_integral_base<short int> : public true_type {};

	template <>
	struct is_integral_base<int> : public true_type {};

	template <>
	struct is_integral_base<long int> : public true_type {};

	// template <>
	// struct is_integral_base<long long int> : public true_type {};

	template <>
	struct is_integral_base<unsigned char> : public true_type {};

	template <>
	struct is_integral_base<unsigned short int> : public true_type {};

	template <>
	struct is_integral_base<unsigned int> : public true_type {};

	template <>
	struct is_integral_base<unsigned long int> : public true_type {};

	// template <>
	// struct is_integral_base<unsigned long long int> : public true_type {};

// int만구현한 이유! 다른자료형이 필요하지 않아서...
// reference에 명시되어있음

/* is_integral */
template <typename T>
struct is_integral
  : public is_integral_base<typename remove_cv<T>::type> {};

}


#endif