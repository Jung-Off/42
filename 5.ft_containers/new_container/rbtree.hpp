#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "iterator_traits.hpp"

namespace ft {
    /* tree_node */
    // 원하는 데이터 형을 저장할 struct를 _tree_node
    // iterator가 node안에 있으면 다음 node로 이동을 할 수 없다.
    // 이 node들 끼리의 이동을 하기 위함이 iterator

    template <typename T>
    struct _tree_node {
        typedef T value_type;
        typedef bool binary_type; // black인지 확인하게 하는 타입!

        _tree_node* _parent;
        _tree_node* _left;
        _tree_node* _right;
        value_type _value; // 
        binary_type _is_black;

        /* constructor & destructor */
        _tree_node(void) : _parent(ft::nil), _left(ft::nil), _right(ft::nil),
                            _value(value_type()), _is_black(binary_type()) {}

        // value initialize
        _tree_node(const value_type& value) : _parent(ft::nil), _left(ft::nil), _right(ft::nil),
                                                _value(value), _is_black(binary_type()) {}

        // copy
        _tree_node(const _tree_node& n) : _parent(n._parent), _left(n._left), _right(n._right),
                                            _value(n._value), _is_black(n._is_black) {}
        ~_tree_node(void) {}

        /* member function for util */
        _tree_node& operator=(const _tree_node& n) {
            if (this != &n) {
                _parent = n._parent;
                _left = n._left;
                _right = n._right;
                _value = n._value;
                _is_black = n._is_black;
            }
            return *this;
        }
    };

    /* non member function for util */
    template <class NodePtr>
    bool _is_left_child(const NodePtr& ptr) {
        return ptr == ptr->_parent->_left;
    }

    template <class NodePtr>
    bool _is_right_child(const NodePtr& ptr) {
        return ptr == ptr->_parent->_right;
    }

    template <class NodePtr>
    bool _is_black_color(const NodePtr& ptr) {
        return ptr->_is_black;
    }

    template <class NodePtr>
    bool _is_red_color(const NodePtr& ptr) {
        return !ptr->_is_black;
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
    NodePtr _get_min_node(NodePtr ptr, NodePtr nil) {
        while (ptr->_left != nil) {
            ptr = ptr->_left;
        }
        return ptr;
    }

    // 큰 값 찾아가는 함수
    template <class NodePtr>
    NodePtr _get_max_node(NodePtr ptr, NodePtr nil) {
        while (ptr->_right != nil) {
            ptr = ptr->_right;
        }
        return ptr;
    }

    // root 노드가 end의 left 차일드
    template <class NodePtr>
    NodePtr _get_next_node(NodePtr ptr, NodePtr nil) {
        // 오른쪽이 있을 때 오른쪽 것의 가장작은 것이 내 다음의 값
        if (ptr->_right != nil) {
            return _get_min_node(ptr->_right, nil);
        }
        // 오른쪽이 없을 때 자신이 왼쪽인 것을 확인하기 위함 (왼쪽이 작음 오른쪽이 큼)
        // 누군가의 자식으로 오른쪽에 있고 왼쪽임을 알기 위해서
        // end()에서 nil을 찍기 위함!
        while (!_is_left_child(ptr)) {
            ptr = ptr->_parent;
        }
        // 부모를 반환해야 내 다음값!
        return ptr->_parent;
    }

    template <class NodePtr>
    NodePtr _get_prev_node(NodePtr ptr, NodePtr nil) {
        if (ptr->_left != nil) {
            return _get_max_node(ptr->_left, nil);
    }
        while (!_is_right_child(ptr)) {
            ptr = ptr->_parent;
    }
        return ptr->_parent;
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
    bool _is_equal(const U& u, const V& v, Comp comp) {
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
    class _tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, U> {
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
            _tree_iterator(void) : _cur(ft::nil), _nil(ft::nil) {}

            _tree_iterator(node_pointer cur, node_pointer nil)
                : _cur(cur), _nil(nil) {}

            _tree_iterator(const _tree_iterator& i)
                : _cur(i._cur), _nil(i._nil) {}

            ~_tree_iterator(void) {}

            /* member function for util */
            _tree_iterator& operator=(const _tree_iterator& i) {
                if (this != &i) {
                    _cur = i._cur;
                    _nil = i._nil;
                }
                return *this;
            }


            /* element access */
            
            // 3. 현재 가리키고 있는 노드의 주소
            node_pointer base(void) const { return _cur; }

            // 4.어떻게, 뭐에 접근을 하는 거임?( ? value ) // pair의 주소!
            pointer operator->(void) const { return &(_cur->_value); } //value(pair자체)는 그냥 값, 주소 접근위해 &
            // node
            // 안에 _value (-> pair<key, value>)

            // Node* current;
            // _value가 node안의 값(pair)에 접근한 것!

            reference operator*(void) const { return _cur->_value; } // 값에 접근

            /* increment & decrement */
            _tree_iterator& operator++(void) {
                _cur = ft::_get_next_node(_cur, _nil);
                return *this;
            }
            _tree_iterator& operator--(void) {
                _cur = ft::_get_prev_node(_cur, _nil);
                return *this;
            }
            _tree_iterator operator++(int) {
                _tree_iterator tmp(*this); // copy con
                ++(*this); // 위의 ++연산자!를 사용한다!
                return tmp;
            }
            _tree_iterator operator--(int) {
                _tree_iterator tmp(*this);
                --(*this);
                return tmp;
            }

            /* relational operators */
            template <typename T>
            bool operator==(const _tree_iterator<T, node_type>& i) const {
                return _cur == i.base();
            }
            template <typename T>
            bool operator!=(const _tree_iterator<T, node_type>& i) const {
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
            operator _tree_iterator<const value_type, node_type>(void) const {
                return _tree_iterator<const value_type, node_type>(_cur, _nil);
            }
            // const 붙은 iterator 
            // (위에가 없으면 const int라고 하면, int와는 다른! const int 라는 새로운 template 객체가 생성이된다!)
            // tree iterator가 생성이 되어있는데 const int가 붙은 새로운 iterator를 >> 이미 있는 것으로 사용하기 위해서!

            // 인자가 두 개 일때!
            /* non member function for util */
            // friend bool operator==(const _tree_iterator& x, const _tree_iterator& y) {
            //     return x._cur == y._cur;
            // }
            // friend bool operator!=(const _tree_iterator& x, const _tree_iterator& y) {
            //     return !(x == y);
            // }

        private:
            
            node_pointer _cur;
            node_pointer _nil;
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
    class _rbtree {
        public:
            typedef T value_type;   // pair
            typedef Key key_type;   // key
            typedef Comp compare_type;  // value전체로 key 비교

            typedef _tree_node<value_type> node_type; // node에 pair를 넣어
            typedef _tree_node<value_type>* node_pointer;

            typedef _tree_iterator<value_type, node_type> iterator; // pair와 node 타입으로 만든 iterator
            typedef _tree_iterator<const value_type, node_type> const_iterator; // const 따로

            typedef Allocator allocator_type;

            typedef typename allocator_type::template rebind<node_type>::other node_allocator; //template인자로 할당하는 것이 아닌 node크기의 할당
            typedef std::allocator_traits<node_allocator> node_traits; // node의 특성 바꾸기

            typedef std::size_t size_type;
            typedef std::ptrdiff_t difference_type;

            /* constructor & destructor */
            _rbtree(const compare_type& comp, const allocator_type& alloc) // comp,, alloc tree에서 생성하는 기본 생성자
                : _comp(comp), _alloc(alloc), _size(size_type()) {
                _nil = _alloc.allocate(1);            // 공간할당
                _alloc.construct(_nil, value_type()); // 객체추가
                _nil->_is_black = true;
                _nil->_parent = _nil;
                _nil->_left = _nil;
                _nil->_right = _nil;
                _end = _construct_node(value_type());
                _end->_is_black = true;
                _root = _end;
            }
            _rbtree(const _rbtree& t) // copy
                : _comp(t._comp), _alloc(t._alloc), _size(size_type()) {
                _nil = _alloc.allocate(1);
                _alloc.construct(_nil, value_type());
                _nil->_is_black = true;
                _nil->_parent = _nil;
                _nil->_left = _nil;
                _nil->_right = _nil;
                _end = _construct_node(value_type());
                _end->_is_black = true;
                _root = _end;
                insert(t.begin(), t.end());
            }
            ~_rbtree(void) { // 소멸자
                _destruct_node_recursive(_end); // 하나하나씩 지우기
                _destruct_node(_nil);
            }

            /* member function for util */
            // 대입 연산자

            //복사하는 이유?! 포인터라서?!
            _rbtree& operator=(const _rbtree& t) {
                if (this != &t) {
                    _rbtree tmp(t);    // tmp에 t 대입 t의 내용 바꾸면 안되서!
                    swap(tmp);          // 현재랑 tmp랑 바꾸고 this에 tmp내용
                }
                return *this;           // tmp소멸
            }

            /* iterators */

            // iterator 생성자 fill
            iterator begin(void) {
                return iterator(_root, _nil);
            }

            // const 가 붙어서 나오는 거 거쳐서 iterator생성자 들렸다가 나옴
            const_iterator begin(void) const {
                return const_iterator(_root, _nil);
            }
            iterator end(void) {
                return iterator(_end, _nil);
            }
            const_iterator end(void) const {
                return const_iterator(_end, _nil);
            }

            /* capacity */
            size_type size(void) const {
                return _size;
            }

            size_type max_size(void) const {
                return (_alloc.max_size());
            }

            bool empty(void) const {
                return _size == 0;
            }

            /* modifiers */
            // 추가한다                                          pair
            // 있는 값이면 false 반환하도록!
            ft::pair<iterator, bool> insert(const value_type& value) {
                node_pointer ptr = _search_parent(value); // 부모 찾는 함수!?
                if (ptr != _end && _is_equal(ptr->_value, value, _comp)) { // 내부에 값이 존재 할때, 같은지 확인 key
                    return ft::make_pair(iterator(ptr, _nil), false); // 쌍으로 반환 (같은 친구의 위치)
                }
                    return ft::make_pair(iterator(_insert_internal(value, ptr), _nil), true); // insert_internal rb 균형맞추기!
            }
            // map 이니까 key가 같은데 value가 달라
            // key가 없으면 넣는다! map의 기본 모토다!
            // key를 넣는거니까! key가 겹치면 안넣는거고
            // value바꾸기 위해서는 접근해서 바꾸기만 가능!

            iterator insert(iterator position, const value_type& value) {
                node_pointer ptr = _search_parent(value, position.base());
                if (ptr != _end && _is_equal(ptr->_value, value, _comp)) {
                    return iterator(ptr, _nil);
                }
                    return iterator(_insert_internal(value, ptr), _nil);
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
                if (_size == 0) {
                    return iterator(_nil, _nil);
                }
                iterator tmp(position);
                ++tmp;
                if (position == begin()) {
                    _root = tmp.base(); // 시작점 바꿔주기!
                }
                --_size;
                _remove_internal(position.base()); // 제거 알고리즘
                _destruct_node(position.base()); // 노드제거
                return tmp;
            }

            // 노드삭제하고 1반환 없으면 0반환
            template <typename U>
            size_type erase(const U& value) {
                iterator i(_find_internal(value), _nil);
                if (i == end()) {
                    return 0;
                }
                if (i == begin()) {
                    iterator tmp(i);
                    ++tmp;
                    _root = tmp.base();
                }
                --_size;
                _remove_internal(i.base());
                _destruct_node(i.base());
                return 1;
            }
            void erase(iterator first, iterator last) {
                for ( ; first != last ; ) {
                    first = erase(first);
                }
            }

            // 포인터 바꿔주는 것!
            void swap(_rbtree& t) {
                std::swap(_nil, t._nil);
                std::swap(_root, t._root);
                std::swap(_end, t._end);
                std::swap(_comp, t._comp);
                std::swap(_alloc, t._alloc);
                std::swap(_size, t._size);
            }

            // tmp this랑 tmp tmp는 스택이니까 clear가 종료될 때 같이 사라지게 끔하는 특성을 이용!
            void clear(void) {
                _rbtree tmp(_comp, _alloc);
                swap(tmp);
            }

            /* lookup operations */
            // nil을 사용하기 위함?
            // key의 iterator 반환
            iterator find(const key_type& key) {
                return iterator(_find_internal(key), _nil);
            }
            const_iterator find(const key_type& key) const {
                return const_iterator(_find_internal(key), _nil);
            }
            iterator lower_bound(const key_type& key) {
                return iterator(_lower_bound_internal(key), _nil);
            }
            const_iterator lower_bound(const key_type& key) const {
                return const_iterator(_lower_bound_internal(key), _nil);
            }
            iterator upper_bound(const key_type& key) {
                return iterator(_upper_bound_internal(key), _nil);
            }
            const_iterator upper_bound(const key_type& key) const {
                return const_iterator(_upper_bound_internal(key), _nil);
            }
            ft::pair<iterator, iterator> equal_range(const key_type& key) {
                return _equal_range_internal(key);
            }
            ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
                return _equal_range_internal(key);
            }

            /* allocator */
            allocator_type get_allocator(void) const {
                return _alloc;
            }

            private:
                node_pointer _nil;
                node_pointer _root;   // root
                node_pointer _end;     // end의 왼쪽 자식이 루트
                compare_type _comp;
                node_allocator _alloc;
                size_type _size;
    
            /* root */
            // 루트 getter
            node_pointer _get_root(void) const {
                return _end->_left;
            }

            // 루트 설정
            void _set_root(const node_pointer ptr) {
                ptr->_parent = _end;
                _end->_left = ptr;
            }

            /* modifiers */
            // 노드 생성하고, 그 노드의 주소 반환 
            node_pointer _construct_node(const value_type& value) {
                node_pointer ptr = _alloc.allocate(1);
                _alloc.construct(ptr, value);
                ptr->_parent = _nil;
                ptr->_left = _nil;
                ptr->_right = _nil;
                ptr->_is_black = false;
                return ptr;
            }
            
            // 노드 삭제
            void _destruct_node(node_pointer ptr) {
                _alloc.destroy(ptr); // 객체 삭제
                _alloc.deallocate(ptr, 1); // 할당 공간 삭제
            }

            // 트리해제할때 재귀를 돌리면서 다 지우기?
            // ptr기준 왼 오 다지우기
            void _destruct_node_recursive(node_pointer ptr) {
                if (ptr == _nil) {
                    return;
                }
                _destruct_node_recursive(ptr->_left);
                _destruct_node_recursive(ptr->_right);
                _destruct_node(ptr);
            }
            
            // insert할 때 어디다 해야할 지 알아야 되니까!
            // 규칙에 맞게! 트리를 만들기 위해서 추가만 한다!
            // 부모가 될 노드찾기
            // 그 value의 부모가 될!
            // nil? insert함수를 빨리 하기위함
            // 넣어야할 위치를 알고 있을 때! position
            // 없으면 루트 부터
            node_pointer _search_parent(const value_type& value, node_pointer position = ft::nil) {
                if (position && position != _end) {
                    if (_comp(value, position->_value) && position->_left == _nil) {
                        iterator prev = iterator(position, _nil);
                        if (prev == begin() || _comp(*--prev, value)) {
                            return position;
                        }
                    } else if (position->_right == _nil) {
                        iterator next = iterator(position, _nil);
                        if (next == end() || _comp(value, *++next)) {
                            return position;
                        }
                    }
                }
                // position이 주어졌을 때 찾는 코드

                // 아래는 루트 부터 찾는 것!
                node_pointer cur = _get_root();
                node_pointer tmp = _end;
                for ( ; cur != _nil ; ) {
                    tmp = cur;
                    if (_comp(value, cur->_value)) {
                        cur = cur->_left;
                    } else if (_comp(cur->_value, value)) {
                        cur = cur->_right;
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
            node_pointer _insert_internal(const value_type& value, node_pointer parent) {
                node_pointer ptr = _construct_node(value);
                if (parent == _end) { // root니까
                  _set_root(ptr);
                } else if (_comp(value, parent->_value)) {
                    parent->_left = ptr;
                } else {
                    parent->_right = ptr;
                }
                ptr->_parent = parent;
                _insert_fixup(ptr);
                _insert_update(ptr);
                return ptr;
            }


            // 삽임할때 규칙 수정!
            void _insert_fixup(node_pointer ptr) {
                while (_is_red_color(ptr->_parent)) {
                    if (_is_left_child(ptr->_parent)) { 
                        _insert_fixup_left(ptr);
                    } else {    // 50은 right입니다
                        _insert_fixup_right(ptr);
                    }
                }
                _get_root()->_is_black = true;
            }

            // 해당 노드의 부모가 왼쪽자식일 경우
            void _insert_fixup_left(node_pointer& ptr) {
                node_pointer uncle = ptr->_parent->_parent->_right;
                if (_is_red_color(uncle)) {
                    ptr->_parent->_is_black = true;
                    uncle->_is_black = true;
                    uncle->_parent->_is_black = false;
                    ptr = uncle->_parent;
                } else {
                    if (_is_right_child(ptr)) {
                        ptr = ptr->_parent;
                        _rotate_left(ptr);
                    }
                    ptr->_parent->_is_black = true;
                    ptr->_parent->_parent->_is_black = false;
                    _rotate_right(ptr->_parent->_parent);
                }
            }

            // 해당 노드의 부모가 오른쪽자식일 경우
            void _insert_fixup_right(node_pointer& ptr) {
                node_pointer uncle = ptr->_parent->_parent->_left; // uncle이 10
                if (_is_red_color(uncle)) { // 여기
                    ptr->_parent->_is_black = true;
                    uncle->_is_black = true;
                    uncle->_parent->_is_black = false;
                    ptr = uncle->_parent;
                } else {
                    if (_is_left_child(ptr)) {
                        ptr = ptr->_parent;
                        _rotate_right(ptr);
                    }
                    ptr->_parent->_is_black = true;
                    ptr->_parent->_parent->_is_black = false;
                    _rotate_left(ptr->_parent->_parent);
                }
            }

            void _insert_update(const node_pointer ptr) {
                if (_root == _end || _comp(ptr->_value, _root->_value)) {
                    _root = ptr;
                }
                    _size++;
            }

            //doubly black
            // recolor_node(doubly black)
            // 삭제 후 RB트리 속성 위반 여부 확인

            // 40지우기!
            void _remove_internal(node_pointer ptr) {
                node_pointer recolor_node;
                node_pointer fixup_node = ptr; // 올리는 과정에서 노드를 기억하기 위함!
                bool original_color = _is_black_color(ptr);

                // 노드 삭제
                if (ptr->_left == _nil) {                             // 왼쪽자식이 없으면 오른쪽 자식
                    recolor_node = ptr->_right;
                    _transplant(ptr, ptr->_right);                    // trandplant 첫번째 자리 노드에 두번째 자리 노드
                } else if (ptr->_right == _nil) {                     // 오른쪽걸 ptr에
                    recolor_node = ptr->_left;
                    _transplant(ptr, ptr->_left);
                } else {                                                // 40지우기
                    fixup_node = _get_min_node(ptr->_right, _nil);   //40 succor          45
                    original_color = _is_black_color(fixup_node);      // black 45
                    recolor_node = fixup_node->_right;                 // 45 오른쪽은 nil
                    if (fixup_node->_parent == ptr) {                  // 40                         
                        recolor_node->_parent = fixup_node;
                }   else {
                    _transplant(fixup_node, fixup_node->_right);      // 45자리에 nil을 붙인다!
                    fixup_node->_right = ptr->_right;                 // 45오른쪽 50
                    fixup_node->_right->_parent = fixup_node;         // 50부모 45
                }
                    _transplant(ptr, fixup_node);                      // 45랑 20 
                    fixup_node->_left = ptr->_left;
                    fixup_node->_left->_parent = fixup_node;
                    fixup_node->_is_black = _is_black_color(ptr);
                }
                if (original_color) {                                   // doubly black을 제거
                    _remove_fixup(recolor_node);                       // 오른쪽 nil
                }
            }

            void _remove_fixup(node_pointer ptr) {
                while (ptr != _get_root() && _is_black_color(ptr)) {
                    if (_is_left_child(ptr)) {     
                        _remove_fixup_left(ptr);
                    } else {                                            // nil 45의 오른쪽 자식
                        _remove_fixup_right(ptr);
                    }
                }                
                ptr->_is_black = true;                                 //red & black 일때만!
            }

            void _remove_fixup_left(node_pointer& ptr) {
                node_pointer sibling = ptr->_parent->_right; 
                if (_is_red_color(sibling)) {                          // 형제이 red
                    sibling->_is_black = true;
                    ptr->_parent->_is_black = false;
                    _rotate_left(ptr->_parent);
                    sibling = ptr->_parent->_right;
                }
                if (_is_black_color(sibling->_left) && _is_black_color(sibling->_right)) { //형제의 왼쪽 블랙 && 형제의 오른쪽 블랙
                    sibling->_is_black = false;
                    ptr = ptr->_parent;
                } else if (_is_black_color(sibling->_right)) {        // 형제의 오른쪽만 블랙
                    sibling->_left->_is_black = true;
                    sibling->_is_black = false;
                    _rotate_right(sibling);
                    sibling = ptr->_parent->_right;
                }
                if (_is_red_color(sibling->_right)) {                 // 형제의 오른쪽 빨간색
                    sibling->_is_black = _is_black_color(ptr->_parent);
                    ptr->_parent->_is_black = true;
                    sibling->_right->_is_black = true;
                    _rotate_left(ptr->_parent);
                    ptr = _get_root();
                }
            }

            // 오른쪽 nil 이 45에 연결이 되어져 있다
            void _remove_fixup_right(node_pointer& ptr) {
                            //          nil     45      20
                node_pointer sibling = ptr->_parent->_left; 
                if (_is_red_color(sibling)) {
                    sibling->_is_black = true;
                    ptr->_parent->_is_black = false;
                    _rotate_right(ptr->_parent);
                    sibling = ptr->_parent->_left;
                }
                if (_is_black_color(sibling->_right) && _is_black_color(sibling->_left)) {
                    sibling->_is_black = false;
                    ptr = ptr->_parent;
                } else if (_is_black_color(sibling->_left)) {
                    sibling->_right->_is_black = true;
                    sibling->_is_black = false;
                    _rotate_left(sibling);
                    sibling = ptr->_parent->_left;
                }
                // case 4 nil일때 여기로 와
                if (_is_red_color(sibling->_left)) {
                    sibling->_is_black = _is_black_color(ptr->_parent); // 시블링 색 == 부모 색
                    ptr->_parent->_is_black = true;                   // 부모
                    sibling->_left->_is_black = true;                 // 형제의 왼쪽
                    _rotate_right(ptr->_parent);                      // 45
                    ptr = _get_root();
                }
            }

            // 이식
            void _transplant(node_pointer former, node_pointer latter) {
                if (former->_parent == _end) {
                  _set_root(latter);
                } else if (_is_left_child(former)) {
                    former->_parent->_left = latter;
                } else {
                    former->_parent->_right = latter;
                }
                    latter->_parent = former->_parent;
            }

            void _rotate_left(node_pointer ptr) {
                node_pointer child = ptr->_right;
                ptr->_right = child->_left;
                if (ptr->_right != _nil) {
                  ptr->_right->_parent = ptr;
                }
                node_pointer parent = ptr->_parent;
                child->_parent = parent;
                if (parent == _end) {
                    _set_root(child);
                } else if (_is_left_child(ptr)) {
                    parent->_left = child;
                } else {
                    parent->_right = child;
                }
                child->_left = ptr;
                ptr->_parent = child;
            }

                                                                        // 45
            void _rotate_right(node_pointer ptr) {
                node_pointer child = ptr->_left;                       // 20
                ptr->_left = child->_right;                           // 45의 왼쪽이 27이랑 연결
                if (ptr->_left != _nil) {                             // 20
                    ptr->_left->_parent = ptr;                        // 27의 부모가 45이다
                }
                node_pointer parent = ptr->_parent;                    //parentr가 end 45의 부모는 end
                child->_parent = parent;                               //20부모가 end
                if (parent == _end) {
                    _set_root(child);                                  //루트다!
                } else if (_is_left_child(ptr)) {                      // ptr이왼쪽 자식이야
                    parent->_left = child; 
                } else {                                                // 오른쪽 자식이다
                    parent->_right = child;
                }
                child->_right = ptr;                                   // ptr이 45 20의 오른쪽 45
                ptr->_parent = child;                                  // 45의 부모가 20이다!
            }

            /* lookup operations */
            template <typename U>
            node_pointer _find_internal(const U& value) const {
                node_pointer ptr = _get_root();
                while (ptr != _nil) {
                    if (_comp(value, ptr->_value)) {
                        ptr = ptr->_left;
                    } else if (_comp(ptr->_value, value)) {
                        ptr = ptr->_right;
                    } else {
                        return ptr;
                    }
                }
                return _end;
            }

            node_pointer _lower_bound_internal(const key_type& key) const {
                node_pointer ptr = _get_root();
                node_pointer tmp = _end;
                while (ptr != _nil) {
                    if (!_comp(ptr->_value, key)) {
                        tmp = ptr;
                        ptr = ptr->_left;
                    } else {
                        ptr = ptr->_right;
                    }
                }
                return tmp;
            }

            node_pointer _upper_bound_internal(const key_type& key) const {
                node_pointer ptr = _get_root();
                node_pointer tmp = _end;
                while (ptr != _nil) {
                    if (_comp(key, ptr->_value)) {
                        tmp = ptr;
                        ptr = ptr->_left;
                    } else {
                        ptr = ptr->_right;
                    }
                }
                return tmp;
            }

            template <typename U>
            ft::pair<iterator, iterator> _equal_range_internal(const U& value) {
                node_pointer ptr = _get_root();
                node_pointer tmp = _end;
                while (ptr != _nil) {
                    if (_comp(value, ptr->_value)) {
                        tmp = ptr;
                        ptr = ptr->_left;
                    } else if (_comp(ptr->_value, value)) {
                        ptr = ptr->_right;
                    } else {
                        if (ptr->_right != _nil) {
                            tmp = _get_min_node(ptr->_right, _nil);
                        }
                        return ft::make_pair(iterator(ptr, _nil), iterator(tmp, _nil));
                    }
                }
                return ft::make_pair(iterator(tmp, _nil), iterator(tmp, _nil));
            }

            template <typename U>
            ft::pair<const_iterator, const_iterator> _equal_range_internal(const U& value) const {
                node_pointer ptr = _get_root();
                node_pointer tmp = _end;
                while (ptr != _nil) {
                    if (_comp(value, ptr->_value)) {
                        tmp = ptr;
                        ptr = ptr->_left;
                    } else if (_comp(ptr->_value, value)) {
                        ptr = ptr->_right;
                    } else {
                        if (ptr->_right != _nil) {
                        tmp = _get_min_node(ptr->_right, _nil);
                        }
                        return ft::make_pair(const_iterator(ptr, _nil), const_iterator(tmp, _nil));
                    }
                }
                return ft::make_pair(const_iterator(tmp, _nil), const_iterator(tmp, _nil));
            }

    };

}
#endif