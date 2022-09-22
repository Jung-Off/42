#ifndef MAP_HPP
#define MAP_HPP

#include <functional> // std::less
#include <memory> // std::allocator
#include "algorithm.hpp" // lexcio, equal
#include "pair.hpp" // ft::pair
#include "random_access_iterator.hpp" // random
#include "rbtree.hpp" // rbtree
#include "reverse_iterator.hpp" // reverse
#include "iterator_traits.hpp"

namespace ft {

    // 1. less ??

    // key만 비교하면 되니까 U만 넣는다!
    //  template <class T> struct less : binary_function <T,T,bool> {
    //  bool operator() (const T& x, const T& y) const {return x<y;} // 기능적으로는 < 연산자와 동일한 기능이다.
    //  };
    //  내림 차순이 될거다!

    //  binary_function 클래스 자체는 다음과 같은 typedef 만을 포함하고 있다.
    //  template <class Arg1, class Arg2, class Result>
    //  struct binary_function {
    //     typedef Arg1 first_argument_type;
    //     typedef Arg2 second_argument_type;
    //     typedef Result result_type;
    //  };

    // const U로 받는 이유? >> key 값은 바뀌지 않으니까!
    // node를 삭제하지 않는 이상 U가 바뀔일이 없지 않을까?
    // std::allocator로 pair를 생성을 할 수 있구나?!
    // std::allocator<ft::pair<const U, V> > >> std::allocator<T> 자리에 pair가 들어간다

    template <typename U, typename V, class Compare = std::less<U>,
            class Allocator = std::allocator<ft::pair<const U, V> > >
                                                // const int, string
                                                // int,         string
                                                // 두개가 다른 template 형식
                                                // map의 pair에서는 key, value니까 key를 const
    class map {
        public:
            typedef U key_type;
            typedef V mapped_type;

            // 이런식으로 받아서 typedef를 할 수도 있구나!
            typedef ft::pair<const U, V> value_type;
            typedef Compare key_compare;

            typedef Allocator allocator_type;


            // http://egloos.zum.com/sweeper/v/2966785
            // int를 할당하는 뿐 아니라 int 다음 그 전을 가르킬 공간 까지 할당을 해주기 위함!
            // int 만을 할당해서는 4바이트만 할당이 됨(실상은 2개의 포인터 + int 12 바이트! 가 필요)
            // 해당 쳄플릿 매개변수 T 타입의 컨테이너 allocator는 T타입이 아닌 다른 타입에 대한 allocate
            // 가 필요해 진다. >> (다른 타입이라함은 해당 컨테이너에서 요구되는 진정한 할당 타입!)
            // typedef typename allocator_type::template rebind<value_type>::other type_allocator;
            // 벡터의 템플릿이 이미 결정이 되어서 들어왔는데 그 안에 있는 것을 다른 유형으로 다시 생성을 한다

            // 노드 하나의 타입이 노드로써 set<int>

                // int
            // int   int
            // map < string, int >
            // >> string 으로 받아 온 것을 rebind Node <pair<string, int> 타입으로 받을 때 

            // string 보다 더 큰 (Node, pair) 타입을 이용해서 다른 형태의 allocator로 변환

            // 저번에 들어봤던거 같음 allocator를 바꾸기 위함? value 말고도 node를 할당해야 되니까!
            // std::allocator<ft::pair<const U, V> 이렇게 되면 pair만큼만 할당을 한다!
            // 다른 구성요소들이 들어갈 메모리가 더 필요해
            typedef typename allocator_type::template rebind<value_type>::other type_allocator;
            
            // allocator_traits에서 뽑아 온것!
            typedef std::allocator_traits<type_allocator> type_traits;

            typedef typename type_traits::pointer pointer;
            typedef typename type_traits::const_pointer const_pointer;
            typedef value_type& reference;
            typedef const value_type& const_reference;

            typedef std::size_t size_type;
            typedef std::ptrdiff_t difference_type;
    
        /* value_compare */
        // keycompare key
        // pair 전체가 들어와도 key를 비교하기 위함!

        // 중첨 클래스는 뭐야? 굳이 뺄 필요가 없으니까 밖에서 쓸일이 없으니까!
        class value_compare
            // binary_function 이건 또 뭐야 ? 11에서는 사라질 예정
            // : public std::binary_function<value_type, value_type, bool>{
            // 이 부분 없어도 무방
        {
        protected:
            // 뭔가를 비교하려는 도구!!
            key_compare comp;

        public:
            /* constructor & destructor */
            value_compare(key_compare c) : comp(c) {}
            ~value_compare(void) {}

            /* callable operator */

            // 천잰가? 다르다!      // pair
            bool operator()(const value_type& x, const value_type& y) const {
            return comp(x.first, y.first); // key key
            }
            bool operator()(const value_type& x, const key_type& y) const {
            return comp(x.first, y); // key key
            }
            bool operator()(const key_type& x, const value_type& y) const {
            return comp(x, y.first); // key key
            }
        };   

        //rbtree 내부의 것 이용하기
        typedef typename ft::_rbtree<value_type, key_type, value_compare, allocator_type>::iterator iterator;
        typedef typename ft::_rbtree<value_type, key_type, value_compare, allocator_type>::const_iterator const_iterator;
        
        //vector같이 이용하기
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

        /* constructor & destructor */
        explicit map(const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type())
            : _key_comp(comp), _value_comp(comp), _tree(_value_comp, alloc) {}
        // 신기한 방식으로 _tree를 만드네!?

        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::nil)
            : _key_comp(comp), _value_comp(comp), _tree(_value_comp, alloc) {
            insert(first, last);
        }

        map(const map& m)
            : _key_comp(m._key_comp), _value_comp(m._value_comp), _tree(m._tree)
            {}

        ~map(void) {}

        /* member function for util */
        map& operator=(const map& m) {
            if (this != &m) {
                _key_comp = m._key_comp;
                _value_comp = m._value_comp;
                _tree = m._tree;
            }
            return *this;
        }

        /* iterators */

        // 여기 const가 없는 이유?
        // rbtree에서 구현이 되어져 있어서 알아서 const없이도 잘 알아서 나온다

        iterator begin(void) {
            return _tree.begin();
        }
        const_iterator begin(void) const {
            return _tree.begin();
        }
        iterator end(void) {
            return _tree.end();
        }
        const_iterator end(void) const {
            return _tree.end();
        }
        reverse_iterator rbegin(void) {
            return reverse_iterator(end());
        }
        
        const_reverse_iterator rbegin(void) const {
            return reverse_iterator(end());
        }
        reverse_iterator rend(void) {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rend(void) const {
            return reverse_iterator(begin());
        }

        /* capacity */
        bool empty(void) const {
            return _tree.empty();
        }
        size_type size(void) const {
            return _tree.size();
        }
        size_type max_size(void) const {
            return _tree.max_size();
        }

        /* element access */
        
        // map[aa] // 여기까지의 기능 그 이후의 (= a) 대입의 과정은 들어가 있지 않는다
            // 1. mapped_type?!?! 으로 value를 어떻게 넣지!? >> 이 과정은 없음!

            // 트리 안에서 iterator를 뱉는것을 구현을 하면 되는데 귀찮아서 하나로 할려고 위와같은 타입의
            // insert만 활용을 하기 위해서 left value의 타입이 저러하다
            // 있으면 key 참조하는 p, 없으면 0을 추가하기위한 위치의 p 트리내부에서 이것을 판단하는게 bool

            // p.first가 iterator이니까(iter가 first, second) ->second는 value 반환
        mapped_type& operator[](const key_type& key) {
            ft::pair<iterator, bool> p = insert(ft::make_pair(key, mapped_type()));
            return p.first->second;
        }

        // map의 iterator
        mapped_type& at(const key_type& key) {
            iterator i = find(key); // 여기서 찾은 key로 iterator 로 반환해서
            if (i == end()) {
                throw std::out_of_range("index out of range");
            }
            return i->second; // key로 찾은 value return해주기
        }

        // const 형태
        const mapped_type& at(const key_type& key) const {
            const_iterator i = find(key);
            if (i == end()) {
                throw std::out_of_range("index out of range");
            }
            return i->second;
        }

        /* modifiers */
        
        // _tree내부의 value 추가하는 insert함수 들어가기!
        ft::pair<iterator, bool> insert(const value_type& value) {
            return _tree.insert(value);
        }

        // with hint
        // 원소를 삽입하기위한 탐색을 root부터가 아닌 position부터 시작하게 됨.
        // 이런 식으로 특정한 위치에 더 빠른 시간 내에 원소를 삽입할 수 있게 됨.
        // 마찬가지로 key값이 이미 존재할 경우 값은 삽입되지 않으며, 해당 위치의 이터레이터를 리턴함.
        iterator insert(iterator position, const value_type& value) {
            return _tree.insert(position, value);
        }

        // iterator로 insert로 추가
        // first 부터 last 사이에 있는 원소를 복사하여 map에 삽입함.
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last) {
            _tree.insert(first, last);
        }

        // _tree내부에 iterator position 으로 작동하는 erase를 사용하기
        // position에 있는 원소 삭제
        void erase(iterator position) {
            _tree.erase(position);
        }

        // _tree내부에 key_type의 key로 작동하는 erase 부르기
        // 해당 키 값을 가진 원소 삭제, 삭제된 갯수가 리턴됨, 즉 삭제 되었으면 1, 아니면 0
        size_type erase(const key_type& key) {
            return _tree.erase(key);
        }

        // _tree내부에 iterator로 erase호출!
        // first와 last 사이의 모든 원소를 삭제함.
        void erase(iterator first, iterator last) {
            _tree.erase(first, last);
        }

        // _tree내부의 swap호출!
        // 현재 컨테이너와 m과 swap. 
        void swap(map& m) {
            _tree.swap(m._tree);
        }

        // _tree내부의 clear호출!
        void clear(void) {
            _tree.clear();
        }

        /* observers */

        // getter
        // Compare type으로 된 key_compare
        // 내부 값을 정렬하는데 쓰인 key_compare 객체를 리턴함.
        key_compare key_comp(void) const {
            return _key_comp;
        }

        // Compare type으로 된 value_compare
        value_compare value_comp(void) const {
            return _value_comp;
        }

        /* lookup operations */
        // _tree 내부의 find함수로 key가 있는 iterator 반환
        // key값이 k(ey)인 원소를 찾아 해당 원소의 이터레이터를 리턴. 해당 원소가 없을 경우 end()가 리턴됨.
        iterator find(const key_type& key) {
            return _tree.find(key);
        }
        // _tree 내부의 find함수로 key가 있는 iterator 반환
        const_iterator find(const key_type& key) const {
            return _tree.find(key);
        }

        // k(ey)를 key로 가지는 원소의 개수를 리턴.
        // key(키값)에 해당하는 원소들(value들)의 개수를 반환 ?? >> 무조건 1이다.
        // 있냐 없냐
        size_type count(const key_type& key) const {
            return !(find(key) == end());
            // != 안쓴이유 오퍼레이터 구현을 안해서
        }

        // key는 존재하지 않는 값일 수도
        // lower_bound(key) 는 키 값 보다 크거나 같은 값을 갖는 최초의 원소 부분에 대한 iterator 를 찾아서 리턴한다.
        // upper_bound(key) 는 키 값 보다 큰 값이 최초로 나오는 지점에 대한 iterator 를 리턴한다

        // 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
        // 찾으려는 key 값을 초과하는 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함

        // lower_bound함수의 경우 오른쪽 원소 중 기준 원소와 같거나
        // 큰 값 중 가장 왼쪽에 있는 원소의 iterator값을 리턴한다.
        // 같은 값이 들어 갈 수 있나?
        iterator lower_bound(const key_type& key) {
            return _tree.lower_bound(key);
        }
        const_iterator lower_bound(const key_type& key) const {
            return _tree.lower_bound(key);
        }
        
        // upper_bound함수의 경우 컨테이너의 오른쪽 원소 중 기준 원소보다
        // 큰 값중 가장 왼쪽에 있는 원소의 iterator값을 리턴한다.
        iterator upper_bound(const key_type& key) {
            return _tree.upper_bound(key);
        }
        const_iterator upper_bound(const key_type& key) const {
            return _tree.upper_bound(key);
        }

        // 첫번째 iterator 는 lower_bound, 두번째 iterator 는 upper_bound 이다.
        // 컨테이너에 주어진 키를 가진 모든 요소를 ​​포함하는 범위를 반환합니다.

        ft::pair<iterator, iterator> equal_range(const key_type& key) {
            return _tree.equal_range(key);
        }
        ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
            return _tree.equal_range(key);
        }

        /* allocator */
        // tree내부의 get_allocator호출
        allocator_type get_allocator(void) const {
            return _tree.get_allocator();
        }

        private:
            // 2번 질문 value_compare

            // Compare 타입 key_compare
            key_compare _key_comp;

            // Compare 타입 value_compare  class로 초기화
            value_compare _value_comp;

            // 이건 만들어놓은 rbtree를 _tree라는 변수로 만들기!

            // map pair로 넣는데
            // set은 단순 value로
            // 원본타입의 const로 넘겨야 됩니다.

            // 사용자가 이것을 가지고 custom을 하기 위함이다
            // int 값을 set은 const int
            
                        // pair         key     value_compare
                        //                      pair 전체가 들어와도 key를 비교하기 위함!
                        //                      key만 따로 비교를 하진 않고 거의 value 자체를 들고가서 비교를 하는 경우가 많으니까
            ft::_rbtree<value_type, key_type, value_compare, allocator_type> _tree;
            
            // key type을 받는 이유
            // map <std::string, int> a
            
            // map의 value는  pair<const std::string, int> 이거 전체가 map안에 pair로써 들어가

            // a::keytype을 뽑을 때는 std::string이 나와야 하는데
            // pair로 value값이 들어가서 const std::string이 keytype으로 나오게 되어서
            // 원본 타입의 value값이 다르다!

            // 원본 타입의 값(std::string)을 찾을 방법이 없으니까!!!!! key 원본타입의 값을 저장

    };

    /* relational operators */
    template <typename U, typename V, class Compare, class Allocator>
    bool operator==(const ft::map<U, V, Compare, Allocator>& x,
                    const ft::map<U, V, Compare, Allocator>& y) {
        return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
    }

    template <typename U, typename V, class Compare, class Allocator>
    bool operator!=(const ft::map<U, V, Compare, Allocator>& x,
                    const ft::map<U, V, Compare, Allocator>& y) {
        return !(x == y);
    }

    template <typename U, typename V, class Compare, class Allocator>
    bool operator<(const ft::map<U, V, Compare, Allocator>& x,
                const ft::map<U, V, Compare, Allocator>& y) {
        return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    }

    template <typename U, typename V, class Compare, class Allocator>
    bool operator<=(const ft::map<U, V, Compare, Allocator>& x,
                    const ft::map<U, V, Compare, Allocator>& y) {
        return !(y < x);
    }

    template <typename U, typename V, class Compare, class Allocator>
    bool operator>(const ft::map<U, V, Compare, Allocator>& x,
                const ft::map<U, V, Compare, Allocator>& y) {
        return y < x;
    }

    template <typename U, typename V, class Compare, class Allocator>
    bool operator>=(const ft::map<U, V, Compare, Allocator>& x,
                    const ft::map<U, V, Compare, Allocator>& y) {
        return !(x < y);
    }

    /* non member function for util */
    template <typename U, typename V, class Compare, class Allocator>
    void swap(ft::map<U, V, Compare, Allocator>& x,
            ft::map<U, V, Compare, Allocator>& y) {
        x.swap(y);
    }

} // namespace ft

#endif