
#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>

namespace ft {

// Iterator_category ==========================================================

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag, output_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

// ============================================================================

// Iterator traits ============================================================

    template <class Iterator>
    struct iterator_traits {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    };

    //std::
    template <typename T>
    struct iterator_traits<T*> { //template 문법이다 포인터가 들어가면 *을 찾아감
        // 포인터도 iterator처럼 사용하기 위해서 아래와 같은 특수화를 진행시킨다
        // 포인터는 산술연산이 가능하므로, 바로 random_access_iterator_tag로 지정해준다
        typedef ptrdiff_t                   difference_type;
        typedef T                           value_type;
        typedef T*                          pointer;
        typedef T&                          reference;
        typedef random_access_iterator_tag  iterator_category;
    };

    template <typename T>
    struct iterator_traits<const T*> {
        typedef ptrdiff_t                   difference_type;
        typedef T                           value_type;
        typedef const T*                    pointer;
        typedef const T&                    reference;
        typedef random_access_iterator_tag  iterator_category;
    };

// Iterator ===================================================================

	template	<typename	Category, typename	T, typename	Distance = ptrdiff_t,
				typename	Pointer = T*, typename	Reference = T&>
	struct iterator {
		typedef Distance	difference_type;
		typedef T           value_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

// ============================================================================

}

#endif