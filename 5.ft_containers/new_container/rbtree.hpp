#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "iterator_traits.hpp"

namespace ft {
    /* tree_node */
    // 원하는 데이터 형을 저장할 struct를 __tree_node
    // iterator가 node안에 있으면 다음 node로 이동을 할 수 없다.
    // 이 node들 끼리의 이동을 하기 위함이 iterator

    template <typename T>
    struct __tree_node {
        typedef T value_type;
        typedef bool binary_type; // black인지 확인하게 하는 타입!

        __tree_node* __parent;
        __tree_node* __left;
        __tree_node* __right;
        value_type __value; // 
        binary_type __is_black;

        /* constructor & destructor */
        __tree_node(void) : __parent(ft::nil), __left(ft::nil), __right(ft::nil),
                            __value(value_type()), __is_black(binary_type()) {}

        // value initialize
        __tree_node(const value_type& value) : __parent(ft::nil), __left(ft::nil), __right(ft::nil),
                                                __value(value), __is_black(binary_type()) {}

        // copy
        __tree_node(const __tree_node& n) : __parent(n.__parent), __left(n.__left), __right(n.__right),
                                            __value(n.__value), __is_black(n.__is_black) {}
        ~__tree_node(void) {}

        /* member function for util */
        __tree_node& operator=(const __tree_node& n) {
            if (this != &n) {
                __parent = n.__parent;
                __left = n.__left;
                __right = n.__right;
                __value = n.__value;
                __is_black = n.__is_black;
            }
            return *this;
        }
    };

    /* non member function for util */
    template <class NodePtr>
    bool __is_left_child(const NodePtr& ptr) {
        return ptr == ptr->__parent->__left;
    }

    template <class NodePtr>
    bool __is_right_child(const NodePtr& ptr) {
        return ptr == ptr->__parent->__right;
    }

    template <class NodePtr>
    bool __is_black_color(const NodePtr& ptr) {
        return ptr->__is_black;
    }

    template <class NodePtr>
    bool __is_red_color(const NodePtr& ptr) {
        return !ptr->__is_black;
    }

    // ************************ //
    // 1. nil을 따로 넣어주는 이유는?
    // 트리마다 하나의 nil을 가지고 있다.
    // 만들어 놓은 하나의 nil 객체를 가리키게 해야되는데 
    // tree 내부에서 쓰는 그 nil을 매개변수로!
    // class 외부의 논멤버 함수이므로 따로 넣어주어야하고
    // 그 트리의 nil인지를 확인하기 위함

    // rb, iterator
    // rb는 내부에 nil이 있어서 마음껏 접근가능
    // 외부의 함수는 nil을 매개변수로 받아야해서!
    // ************************ //

    // 작은 값 찾아가는 함수
    template <class NodePtr>
    NodePtr __get_min_node(NodePtr ptr, NodePtr nil) {
        while (ptr->__left != nil) {
            ptr = ptr->__left;
        }
        return ptr;
    }

    // 큰 값 찾아가는 함수
    template <class NodePtr>
    NodePtr __get_max_node(NodePtr ptr, NodePtr nil) {
        while (ptr->__right != nil) {
            ptr = ptr->__right;
        }
        return ptr;
    }

    // root 노드가 end의 left 차일드
    template <class NodePtr>
    NodePtr __get_next_node(NodePtr ptr, NodePtr nil) {
        // 오른쪽이 있을 때 오른쪽 것의 가장작은 것이 내 다음의 값
        if (ptr->__right != nil) {
            return __get_min_node(ptr->__right, nil);
        }
        // 오른쪽이 없을 때 자신이 왼쪽인 것을 확인하기 위함 (왼쪽이 작음 오른쪽이 큼)
        // 누군가의 자식으로 오른쪽에 있고 왼쪽임을 알기 위해서
        // end()에서 nil을 찍기 위함!
        while (!__is_left_child(ptr)) {
            ptr = ptr->__parent;
        }
        // 부모를 반환해야 내 다음값!
        return ptr->__parent;
    }

    template <class NodePtr>
    NodePtr __get_prev_node(NodePtr ptr, NodePtr nil) {
        if (ptr->__left != nil) {
            return __get_max_node(ptr->__left, nil);
    }
        while (!__is_right_child(ptr)) {
            ptr = ptr->__parent;
    }
        return ptr->__parent;
    }

    // 이건 뭐여 !F && !F == T
    // int면 a == b 이런식의 비교!
    // compare 는 크다 작다 같다가 아님 >> 그냥 비교
    
    // 크다 같다 작다 비교를 못해서 
    // < , == , >
    // f       f >>>> 이걸로 == 을 만든다!
    
    // 비교하는 멤버함수, 정렬 비교, 오버로딩이 안돼어있어서
    // < 이거하나로 ==을 만들어내야함!

    // keyword mac 정렬 compare class 만들기

    // 근본적인 이유! 
    // cmp라는 것을 하나 밖에 못만든다! (ex "<" )
    // cmp 이거 하나로 양쪽을 비교해야하기 때문에 아래와 같은 코드가 나온다
    // !< >> >=  이고 !> >> <= 인데 &&니까 동시에 만족하는 것은 ==

    template <typename U, typename V, class Comp>
    bool __is_equal(const U& u, const V& v, Comp comp) {
        return !comp(u, v) && !comp(v, u);
    }

    // 기준을 Comp에 맞긴다!
    // Comp 함수, Comp class 일 수도 있어서 함수 사용을 막으면서 까지 == 으로 오버로딩을 하느냐 놉!

    // 2.
    // ************* //
    // comp에서 정한 기준에 적합하면 is_equal
    // ************* //

    /* tree_iterator */
    template <typename U, typename V>
    class __tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, U> {
        public:
            // U, V 이렇게 나누는 이유?
            // 편하게 쓸라고  pair<key, value>
            typedef U value_type;
            typedef value_type* pointer;
            typedef value_type& reference;

            // V가 큰 node이다 위의 pair를 담는 덩어리!(가르키는) iterator
            typedef V* iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
            typedef typename ft::iterator_traits<iterator_type>::value_type node_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer node_pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference node_reference;
            typedef bidirectional_iterator_tag iterator_category;


            /* constructor & destructor */
            __tree_iterator(void) : __cur(ft::nil), __nil(ft::nil) {}

            __tree_iterator(node_pointer cur, node_pointer nil)
                : __cur(cur), __nil(nil) {}

            __tree_iterator(const __tree_iterator& i)
                : __cur(i.__cur), __nil(i.__nil) {}

            ~__tree_iterator(void) {}

            /* member function for util */
            __tree_iterator& operator=(const __tree_iterator& i) {
                if (this != &i) {
                    __cur = i.__cur;
                    __nil = i.__nil;
                }
                return *this;
            }


            /* element access */
            
            // 3. 현재 가리키고 있는 노드의 주소
            node_pointer base(void) const { return __cur; }

            // 4.어떻게, 뭐에 접근을 하는 거임?( ? value ) // pair의 주소!
            pointer operator->(void) const { return &(__cur->__value); } //value(pair자체)는 그냥 값, 주소 접근위해 &
            // node
            // 안에 _value (-> pair<key, value>)

            // Node* current;
            // _value가 node안의 값(pair)에 접근한 것!

            reference operator*(void) const { return __cur->__value; } // 값에 접근

            /* increment & decrement */
            __tree_iterator& operator++(void) {
                __cur = ft::__get_next_node(__cur, __nil);
                return *this;
            }
            __tree_iterator& operator--(void) {
                __cur = ft::__get_prev_node(__cur, __nil);
                return *this;
            }
            __tree_iterator operator++(int) {
                __tree_iterator tmp(*this); // copy con
                ++(*this); // 위의 ++연산자!를 사용한다!
                return tmp;
            }
            __tree_iterator operator--(int) {
                __tree_iterator tmp(*this);
                --(*this);
                return tmp;
            }

            /* relational operators */
            template <typename T>
            bool operator==(const __tree_iterator<T, node_type>& i) const {
                return __cur == i.base();
            }
            template <typename T>
            bool operator!=(const __tree_iterator<T, node_type>& i) const {
                return !(*this == i);
            }
            // const iterator가 없다.
            // value type vec<type_iterator >> const>

            /* const type overloading */
            // iterator에 const 속성을 부여하기 위한 operator

            // U value_type은 iterator_traits 이런걸 거치지 않아서
            // const에 대한게 없어서 value_type에 대해서 const로 들어왔을 때
            // 해결을 하기 위함

            // V는 iterator_type을 거쳐서 const가 되도록 할 수 있어
            // node type에대한 const가 설정
            // value는 const 가 안됨 value에 대한 const 설정을 하기 위함이다!
            //                            U              V
            operator __tree_iterator<const value_type, node_type>(void) const {
                return __tree_iterator<const value_type, node_type>(__cur, __nil);
            }
            // const 붙은 iterator 
            // (위에가 없으면 const int라고 하면, int와는 다른! const int 라는 새로운 template 객체가 생성이된다!)
            // tree iterator가 생성이 되어있는데 const int가 붙은 새로운 iterator를 >> 이미 있는 것으로 사용하기 위해서!

            // 인자가 두 개 일때!
            /* non member function for util */
            // friend bool operator==(const __tree_iterator& x, const __tree_iterator& y) {
            //     return x.__cur == y.__cur;
            // }
            // friend bool operator!=(const __tree_iterator& x, const __tree_iterator& y) {
            //     return !(x == y);
            // }

        private:
            
            node_pointer __cur;
            node_pointer __nil;
            // ************************** //
            // 5. 무엇을 위한 nil? nil 노드들이 모두가 공통으로 가르키게 만드는 곳!
            // ************************** //

            // 3
            // 2 4
            // nil
            // 한개만 생성해서 모두 동일한 nil을 가리키게 한다. 
            // nil은 생성된 객체 
            // 자기가 진짜 마지막인지를 체크하기 위함
            
            // segfault를 안 띄우기 위함
            // if( == NULL) 이거 너무 힘드니까
            // 접근을 해도 터지지 않도록 방지하기 위함
            
            // Node* a;
            
            // a->left ==   NULL 은 가능
            // a->left->left를 해야 알수 있는 경우 많음

            // NULL->left seg
            // if (a->left == NULL)을 넘기는 경우가 많으니까
            // 두단계에 접근 한 경우! >> 방지

            // 만들어놓은 객체 NIL에 접근하기 위함으로 선언을 해 두었다.

    };

    /* rbtree */
                // pair                 value가 들어와도 key 비교
    template <typename T, class Key, class Comp, class Allocator>
    class __rbtree {
        public:
            typedef T value_type;   // pair
            typedef Key key_type;   // key
            typedef Comp compare_type;  // value전체로 key 비교

            typedef __tree_node<value_type> node_type; // node에 pair를 넣어
            typedef __tree_node<value_type>* node_pointer;

            typedef __tree_iterator<value_type, node_type> iterator; // pair와 node 타입으로 만든 iterator
            typedef __tree_iterator<const value_type, node_type> const_iterator; // const 따로

            typedef Allocator allocator_type;

            typedef typename allocator_type::template rebind<node_type>::other node_allocator; //template인자로 할당하는 것이 아닌 node크기의 할당
            typedef std::allocator_traits<node_allocator> node_traits; // node의 특성 바꾸기

            typedef std::size_t size_type;
            typedef std::ptrdiff_t difference_type;

            /* constructor & destructor */
            __rbtree(const compare_type& comp, const allocator_type& alloc) // comp,, alloc tree에서 생성하는 기본 생성자
                : __comp(comp), __alloc(alloc), __size(size_type()) {
                __nil = __alloc.allocate(1);            // 공간할당
                __alloc.construct(__nil, value_type()); // 객체추가
                __nil->__is_black = true;
                __nil->__parent = __nil;
                __nil->__left = __nil;
                __nil->__right = __nil;
                __end = __construct_node(value_type());
                __end->__is_black = true;
                __begin = __end;
            }
            __rbtree(const __rbtree& t) // copy
                : __comp(t.__comp), __alloc(t.__alloc), __size(size_type()) {
                __nil = __alloc.allocate(1);
                __alloc.construct(__nil, value_type());
                __nil->__is_black = true;
                __nil->__parent = __nil;
                __nil->__left = __nil;
                __nil->__right = __nil;
                __end = __construct_node(value_type());
                __end->__is_black = true;
                __begin = __end;
                insert(t.begin(), t.end());
            }
            ~__rbtree(void) { // 소멸자
                __destruct_node_recursive(__end); // 하나하나씩 지우기
                __destruct_node(__nil);
            }

            /* member function for util */
            // 대입 연산자

            //복사하는 이유?! 포인터라서?!
            __rbtree& operator=(const __rbtree& t) {
                if (this != &t) {
                    __rbtree tmp(t);    // tmp에 t 대입 t의 내용 바꾸면 안되서!
                    swap(tmp);          // 현재랑 tmp랑 바꾸고 this에 tmp내용
                }
                return *this;           // tmp소멸
            }

            /* iterators */

            // iterator 생성자 fill
            iterator begin(void) {
                return iterator(__begin, __nil);
            }

            // const 가 붙어서 나오는 거 거쳐서 iterator생성자 들렸다가 나옴
            const_iterator begin(void) const {
                return const_iterator(__begin, __nil);
            }
            iterator end(void) {
                return iterator(__end, __nil);
            }
            const_iterator end(void) const {
                return const_iterator(__end, __nil);
            }

            /* capacity */
            size_type size(void) const {
                return __size;
            }

            size_type max_size(void) const {
                return (__alloc.max_size());
            }

            bool empty(void) const {
                return __size == 0;
            }

            /* modifiers */
            // 추가한다                                          pair
            // 있는 값이면 false 반환하도록!
            ft::pair<iterator, bool> insert(const value_type& value) {
                node_pointer ptr = __search_parent(value); // 부모 찾는 함수!?
                if (ptr != __end && __is_equal(ptr->__value, value, __comp)) { // 내부에 값이 존재 할때, 같은지 확인 key
                    return ft::make_pair(iterator(ptr, __nil), false); // 쌍으로 반환 (같은 친구의 위치)
                }
                    return ft::make_pair(iterator(__insert_internal(value, ptr), __nil), true); // insert_internal rb 균형맞추기!
            }
            // map 이니까 key가 같은데 value가 달라
            // key가 없으면 넣는다! map의 기본 모토다!
            // key를 넣는거니까! key가 겹치면 안넣는거고
            // value바꾸기 위해서는 접근해서 바꾸기만 가능!

            iterator insert(iterator position, const value_type& value) {
                node_pointer ptr = __search_parent(value, position.base());
                if (ptr != __end && __is_equal(ptr->__value, value, __comp)) {
                    return iterator(ptr, __nil);
                }
                    return iterator(__insert_internal(value, ptr), __nil);
            }

            template <class InputIterator>
            void insert(InputIterator first, InputIterator last) {
                for ( ; first != last ; first++) {
                    insert(*first);
                }
            }
            
            // 노드삭제하고
            // 위치를 지우기
            iterator erase(iterator position) {
                if (__size == 0) {
                    return iterator(__nil, __nil);
                }
                iterator tmp(position);
                ++tmp;
                if (position == begin()) {
                    __begin = tmp.base(); // 시작점 바꿔주기!
                }
                --__size;
                __remove_internal(position.base()); // 제거 알고리즘
                __destruct_node(position.base()); // 노드제거
                return tmp;
            }

            // 노드삭제하고 1반환 없으면 0반환
            template <typename U>
            size_type erase(const U& value) {
                iterator i(__find_internal(value), __nil);
                if (i == end()) {
                    return 0;
                }
                if (i == begin()) {
                    iterator tmp(i);
                    ++tmp;
                    __begin = tmp.base();
                }
                --__size;
                __remove_internal(i.base());
                __destruct_node(i.base());
                return 1;
            }
            void erase(iterator first, iterator last) {
                for ( ; first != last ; ) {
                    first = erase(first);
                }
            }

            // 포인터 바꿔주는 것!
            void swap(__rbtree& t) {
                std::swap(__nil, t.__nil);
                std::swap(__begin, t.__begin);
                std::swap(__end, t.__end);
                std::swap(__comp, t.__comp);
                std::swap(__alloc, t.__alloc);
                std::swap(__size, t.__size);
            }

            // tmp this랑 tmp tmp는 스택이니까 clear가 종료될 때 같이 사라지게 끔하는 특성을 이용!
            void clear(void) {
                __rbtree tmp(__comp, __alloc);
                swap(tmp);
            }

            /* lookup operations */
            // nil을 사용하기 위함?
            // key의 iterator 반환
            iterator find(const key_type& key) {
                return iterator(__find_internal(key), __nil);
            }
            const_iterator find(const key_type& key) const {
                return const_iterator(__find_internal(key), __nil);
            }
            iterator lower_bound(const key_type& key) {
                return iterator(__lower_bound_internal(key), __nil);
            }
            const_iterator lower_bound(const key_type& key) const {
                return const_iterator(__lower_bound_internal(key), __nil);
            }
            iterator upper_bound(const key_type& key) {
                return iterator(__upper_bound_internal(key), __nil);
            }
            const_iterator upper_bound(const key_type& key) const {
                return const_iterator(__upper_bound_internal(key), __nil);
            }
            ft::pair<iterator, iterator> equal_range(const key_type& key) {
                return __equal_range_internal(key);
            }
            ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
                return __equal_range_internal(key);
            }

            /* allocator */
            allocator_type get_allocator(void) const {
                return __alloc;
            }

            private:
                node_pointer __nil;
                node_pointer __begin;   // root
                node_pointer __end;     // end의 왼쪽 자식이 루트
                compare_type __comp;
                node_allocator __alloc;
                size_type __size;
    
            /* root */
            // 루트 getter
            node_pointer __get_root(void) const {
                return __end->__left;
            }

            // 루트 설정
            void __set_root(const node_pointer ptr) {
                ptr->__parent = __end;
                __end->__left = ptr;
            }

            /* modifiers */
            // 노드 생성하고, 그 노드의 주소 반환 
            node_pointer __construct_node(const value_type& value) {
                node_pointer ptr = __alloc.allocate(1);
                __alloc.construct(ptr, value);
                ptr->__parent = __nil;
                ptr->__left = __nil;
                ptr->__right = __nil;
                ptr->__is_black = false;
                return ptr;
            }
            
            // 노드 삭제
            void __destruct_node(node_pointer ptr) {
                __alloc.destroy(ptr); // 객체 삭제
                __alloc.deallocate(ptr, 1); // 할당 공간 삭제
            }

            // 트리해제할때 재귀를 돌리면서 다 지우기?
            // ptr기준 왼 오 다지우기
            void __destruct_node_recursive(node_pointer ptr) {
                if (ptr == __nil) {
                    return;
                }
                __destruct_node_recursive(ptr->__left);
                __destruct_node_recursive(ptr->__right);
                __destruct_node(ptr);
            }
            
            // insert할 때 어디다 해야할 지 알아야 되니까!
            // 규칙에 맞게! 트리를 만들기 위해서 추가만 한다!
            // 부모가 될 노드찾기
            // 그 value의 부모가 될!
            // nil? insert함수를 빨리 하기위함
            // 넣어야할 위치를 알고 있을 때! position
            // 없으면 루트 부터
            node_pointer __search_parent(const value_type& value, node_pointer position = ft::nil) {
                if (position && position != __end) {
                    if (__comp(value, position->__value) && position->__left == __nil) {
                        iterator prev = iterator(position, __nil);
                        if (prev == begin() || __comp(*--prev, value)) {
                            return position;
                        }
                    } else if (position->__right == __nil) {
                        iterator next = iterator(position, __nil);
                        if (next == end() || __comp(value, *++next)) {
                            return position;
                        }
                    }
                }
                // position이 주어졌을 때 찾는 코드

                // 아래는 루트 부터 찾는 것!
                node_pointer cur = __get_root();
                node_pointer tmp = __end;
                for ( ; cur != __nil ; ) {
                    tmp = cur;
                    if (__comp(value, cur->__value)) {
                        cur = cur->__left;
                    } else if (__comp(cur->__value, value)) {
                        cur = cur->__right;
                    } else {
                        return cur;
                    }
                }
                return tmp;
            }
 
            // 삽입 1번, 삽입된 노드의 부모가 Red이고, 삼촌 노드도 Red
            //   20
            // 10 50 30추가

            // key를 추가할 때! 여기!
            node_pointer __insert_internal(const value_type& value, node_pointer parent) {
                node_pointer ptr = __construct_node(value);
                if (parent == __end) { // root니까
                  __set_root(ptr);
                } else if (__comp(value, parent->__value)) {
                    parent->__left = ptr;
                } else {
                    parent->__right = ptr;
                }
                ptr->__parent = parent;
                __insert_fixup(ptr);
                __insert_update(ptr);
                return ptr;
            }


            // 삽임할때 규칙 수정!
            void __insert_fixup(node_pointer ptr) {
                while (__is_red_color(ptr->__parent)) {
                    if (__is_left_child(ptr->__parent)) { 
                        __insert_fixup_left(ptr);
                    } else {    // 50은 right입니다
                        __insert_fixup_right(ptr);
                    }
                }
                __get_root()->__is_black = true;
            }

            // 해당 노드의 부모가 왼쪽자식일 경우
            void __insert_fixup_left(node_pointer& ptr) {
                node_pointer uncle = ptr->__parent->__parent->__right;
                if (__is_red_color(uncle)) {
                    ptr->__parent->__is_black = true;
                    uncle->__is_black = true;
                    uncle->__parent->__is_black = false;
                    ptr = uncle->__parent;
                } else {
                    if (__is_right_child(ptr)) {
                        ptr = ptr->__parent;
                        __rotate_left(ptr);
                    }
                    ptr->__parent->__is_black = true;
                    ptr->__parent->__parent->__is_black = false;
                    __rotate_right(ptr->__parent->__parent);
                }
            }

            // 해당 노드의 부모가 오른쪽자식일 경우
            void __insert_fixup_right(node_pointer& ptr) {
                node_pointer uncle = ptr->__parent->__parent->__left; // uncle이 10
                if (__is_red_color(uncle)) { // 여기
                    ptr->__parent->__is_black = true;
                    uncle->__is_black = true;
                    uncle->__parent->__is_black = false;
                    ptr = uncle->__parent;
                } else {
                    if (__is_left_child(ptr)) {
                        ptr = ptr->__parent;
                        __rotate_right(ptr);
                    }
                    ptr->__parent->__is_black = true;
                    ptr->__parent->__parent->__is_black = false;
                    __rotate_left(ptr->__parent->__parent);
                }
            }

            void __insert_update(const node_pointer ptr) {
                if (__begin == __end || __comp(ptr->__value, __begin->__value)) {
                    __begin = ptr;
                }
                    __size++;
            }

            //doubly black
            // recolor_node(doubly black)
            // 삭제 후 RB트리 속성 위반 여부 확인

            // 40지우기!
            void __remove_internal(node_pointer ptr) {
                node_pointer recolor_node;
                node_pointer fixup_node = ptr; // 올리는 과정에서 노드를 기억하기 위함!
                bool original_color = __is_black_color(ptr);

                // 노드 삭제
                if (ptr->__left == __nil) {                             // 왼쪽자식이 없으면 오른쪽 자식
                    recolor_node = ptr->__right;
                    __transplant(ptr, ptr->__right);                    // trandplant 첫번째 자리 노드에 두번째 자리 노드
                } else if (ptr->__right == __nil) {                     // 오른쪽걸 ptr에
                    recolor_node = ptr->__left;
                    __transplant(ptr, ptr->__left);
                } else {                                                // 40지우기
                    fixup_node = __get_min_node(ptr->__right, __nil);   //40 succor          45
                    original_color = __is_black_color(fixup_node);      // black 45
                    recolor_node = fixup_node->__right;                 // 45 오른쪽은 nil
                    if (fixup_node->__parent == ptr) {                  // 40                         
                        recolor_node->__parent = fixup_node;
                }   else {
                    __transplant(fixup_node, fixup_node->__right);      // 45자리에 nil을 붙인다!
                    fixup_node->__right = ptr->__right;                 // 45오른쪽 50
                    fixup_node->__right->__parent = fixup_node;         // 50부모 45
                }
                    __transplant(ptr, fixup_node);                      // 45랑 20 
                    fixup_node->__left = ptr->__left;
                    fixup_node->__left->__parent = fixup_node;
                    fixup_node->__is_black = __is_black_color(ptr);
                }
                if (original_color) {                                   // doubly black을 제거
                    __remove_fixup(recolor_node);                       // 오른쪽 nil
                }
            }

            void __remove_fixup(node_pointer ptr) {
                while (ptr != __get_root() && __is_black_color(ptr)) {
                    if (__is_left_child(ptr)) {     
                        __remove_fixup_left(ptr);
                    } else {                                            // nil 45의 오른쪽 자식
                        __remove_fixup_right(ptr);
                    }
                }                
                ptr->__is_black = true;                                 //red & black 일때만!
            }

            void __remove_fixup_left(node_pointer& ptr) {
                node_pointer sibling = ptr->__parent->__right; 
                if (__is_red_color(sibling)) {                          // 형제이 red
                    sibling->__is_black = true;
                    ptr->__parent->__is_black = false;
                    __rotate_left(ptr->__parent);
                    sibling = ptr->__parent->__right;
                }
                if (__is_black_color(sibling->__left) && __is_black_color(sibling->__right)) { //형제의 왼쪽 블랙 && 형제의 오른쪽 블랙
                    sibling->__is_black = false;
                    ptr = ptr->__parent;
                } else if (__is_black_color(sibling->__right)) {        // 형제의 오른쪽만 블랙
                    sibling->__left->__is_black = true;
                    sibling->__is_black = false;
                    __rotate_right(sibling);
                    sibling = ptr->__parent->__right;
                }
                if (__is_red_color(sibling->__right)) {                 // 형제의 오른쪽 빨간색
                    sibling->__is_black = __is_black_color(ptr->__parent);
                    ptr->__parent->__is_black = true;
                    sibling->__right->__is_black = true;
                    __rotate_left(ptr->__parent);
                    ptr = __get_root();
                }
            }

            // 오른쪽 nil 이 45에 연결이 되어져 있다
            void __remove_fixup_right(node_pointer& ptr) {
                            //          nil     45      20
                node_pointer sibling = ptr->__parent->__left; 
                if (__is_red_color(sibling)) {
                    sibling->__is_black = true;
                    ptr->__parent->__is_black = false;
                    __rotate_right(ptr->__parent);
                    sibling = ptr->__parent->__left;
                }
                if (__is_black_color(sibling->__right) && __is_black_color(sibling->__left)) {
                    sibling->__is_black = false;
                    ptr = ptr->__parent;
                } else if (__is_black_color(sibling->__left)) {
                    sibling->__right->__is_black = true;
                    sibling->__is_black = false;
                    __rotate_left(sibling);
                    sibling = ptr->__parent->__left;
                }
                // case 4 nil일때 여기로 와
                if (__is_red_color(sibling->__left)) {
                    sibling->__is_black = __is_black_color(ptr->__parent); // 시블링 색 == 부모 색
                    ptr->__parent->__is_black = true;                   // 부모
                    sibling->__left->__is_black = true;                 // 형제의 왼쪽
                    __rotate_right(ptr->__parent);                      // 45
                    ptr = __get_root();
                }
            }

            // 이식
            void __transplant(node_pointer former, node_pointer latter) {
                if (former->__parent == __end) {
                  __set_root(latter);
                } else if (__is_left_child(former)) {
                    former->__parent->__left = latter;
                } else {
                    former->__parent->__right = latter;
                }
                    latter->__parent = former->__parent;
            }

            void __rotate_left(node_pointer ptr) {
                node_pointer child = ptr->__right;
                ptr->__right = child->__left;
                if (ptr->__right != __nil) {
                  ptr->__right->__parent = ptr;
                }
                node_pointer parent = ptr->__parent;
                child->__parent = parent;
                if (parent == __end) {
                    __set_root(child);
                } else if (__is_left_child(ptr)) {
                    parent->__left = child;
                } else {
                    parent->__right = child;
                }
                child->__left = ptr;
                ptr->__parent = child;
            }

                                                                        // 45
            void __rotate_right(node_pointer ptr) {
                node_pointer child = ptr->__left;                       // 20
                ptr->__left = child->__right;                           // 45의 왼쪽이 27이랑 연결
                if (ptr->__left != __nil) {                             // 20
                    ptr->__left->__parent = ptr;                        // 27의 부모가 45이다
                }
                node_pointer parent = ptr->__parent;                    //parentr가 end 45의 부모는 end
                child->__parent = parent;                               //20부모가 end
                if (parent == __end) {
                    __set_root(child);                                  //루트다!
                } else if (__is_left_child(ptr)) {                      // ptr이왼쪽 자식이야
                    parent->__left = child; 
                } else {                                                // 오른쪽 자식이다
                    parent->__right = child;
                }
                child->__right = ptr;                                   // ptr이 45 20의 오른쪽 45
                ptr->__parent = child;                                  // 45의 부모가 20이다!
            }

            /* lookup operations */
            template <typename U>
            node_pointer __find_internal(const U& value) const {
                node_pointer ptr = __get_root();
                while (ptr != __nil) {
                    if (__comp(value, ptr->__value)) {
                        ptr = ptr->__left;
                    } else if (__comp(ptr->__value, value)) {
                        ptr = ptr->__right;
                    } else {
                        return ptr;
                    }
                }
                return __end;
            }

            node_pointer __lower_bound_internal(const key_type& key) const {
                node_pointer ptr = __get_root();
                node_pointer tmp = __end;
                while (ptr != __nil) {
                    if (!__comp(ptr->__value, key)) {
                        tmp = ptr;
                        ptr = ptr->__left;
                    } else {
                        ptr = ptr->__right;
                    }
                }
                return tmp;
            }

            node_pointer __upper_bound_internal(const key_type& key) const {
                node_pointer ptr = __get_root();
                node_pointer tmp = __end;
                while (ptr != __nil) {
                    if (__comp(key, ptr->__value)) {
                        tmp = ptr;
                        ptr = ptr->__left;
                    } else {
                        ptr = ptr->__right;
                    }
                }
                return tmp;
            }

            template <typename U>
            ft::pair<iterator, iterator> __equal_range_internal(const U& value) {
                node_pointer ptr = __get_root();
                node_pointer tmp = __end;
                while (ptr != __nil) {
                    if (__comp(value, ptr->__value)) {
                        tmp = ptr;
                        ptr = ptr->__left;
                    } else if (__comp(ptr->__value, value)) {
                        ptr = ptr->__right;
                    } else {
                        if (ptr->__right != __nil) {
                            tmp = __get_min_node(ptr->__right, __nil);
                        }
                        return ft::make_pair(iterator(ptr, __nil), iterator(tmp, __nil));
                    }
                }
                return ft::make_pair(iterator(tmp, __nil), iterator(tmp, __nil));
            }

            template <typename U>
            ft::pair<const_iterator, const_iterator> __equal_range_internal(const U& value) const {
                node_pointer ptr = __get_root();
                node_pointer tmp = __end;
                while (ptr != __nil) {
                    if (__comp(value, ptr->__value)) {
                        tmp = ptr;
                        ptr = ptr->__left;
                    } else if (__comp(ptr->__value, value)) {
                        ptr = ptr->__right;
                    } else {
                        if (ptr->__right != __nil) {
                        tmp = __get_min_node(ptr->__right, __nil);
                        }
                        return ft::make_pair(const_iterator(ptr, __nil), const_iterator(tmp, __nil));
                    }
                }
                return ft::make_pair(const_iterator(tmp, __nil), const_iterator(tmp, __nil));
            }

    };

}
#endif