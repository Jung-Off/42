#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {

    template <typename T, class Container = ft::vector<T> >
    class stack {

    public:
        typedef Container container_type;
        typedef typename container_type::value_type value_type;
        typedef typename container_type::size_type size_type;
        typedef typename container_type::reference reference;
        typedef typename container_type::const_reference const_reference;
        
        /* constructor & destructor */
        // container_type만을 받아서 생성하게 하는 생성자!
        explicit stack(const container_type& container = container_type())
            : c(container) {}
        // stack은 list로도 만들 수 있는데 아래 연산자가 template<Tn>으로 끝나면
        // stack<T, std::list<int> > 로 들어 왔을때는 그에 해당하는 template 연산자가 없어서 오류가 났다 정도?

        // copy constructor
        stack(const stack& s) : c(s.c) {}

        // destructor
        ~stack(void) {}

        /* member function for util */
        // 대입 연산자
        stack& operator=(const stack& s) {
            if (this != &s) {
                c = s.c;
            }
            return *this;
        }

        // 왜 이 기능들만 오버라이딩을 하는지?(이름을 다르게 명명하는지?) >> 기능이 한정이 되어서 정도로 생각
        // vector에서 stack으로 넘어올 때 기능이 제한이 되어서 아래와 같은 기능만 있으면 되어서! 아래의 함수들만 만들었다.
        // 실제 기능은 vector의 함수들로 기능을 한다.

        /* element access */
        reference top(void) {
            return c.back();
        }
        const_reference top(void) const {
            return c.back();
        }

        /* capacity */
        bool empty(void) const {
            return c.empty();
        }

        size_type size(void) const {
            return c.size();
        }

        /* modifiers */
        // vector의 push_back 불러오기
        void push(const value_type& value) {
            c.push_back(value);
        }

        // vector의 pop_back 불러오기
        void pop(void) {
            c.pop_back();
        }

        // friend 라는 키워드를 사용한 이유는?
        // 일단 getc는 없다. 그래서 
        // container_type getc()
        // {
        //     return c;
        // }
        // private, protected 멤버에 접근하기 위해서
        // 외부에서 접근할 수 있게끔

        // 내부의 c비교는 vector의 연산자를 호출할 것 같다.
        /* friend non member function for relational operators */

        // 안에다가 구현을 했어도 friend 비멤버함수이다.
        // friend 키워드가 밖에 있는 다른 객체도 protected c 에 접근 할 수 있음
        // 어짜피 선언을 해줘야 되는 거니까 선언과 구현을 동시에

        // friend 선언 안에, 구현은 밖에

        // friend bool operator==(const stack& x, const stack& y) {
        //     return x.c == y.c;
        // }

        // friend bool operator!=(const stack& x, const stack& y) {
        //     return x.c != y.c;
        // }
        // friend bool operator<(const stack& x, const stack& y) {
        //     return x.c < y.c;
        // }
        // friend bool operator<=(const stack& x, const stack& y) {
        //     return x.c <= y.c;
        // }
        // friend bool operator>(const stack& x, const stack& y) {
        //     return x.c > y.c;
        // }
        // friend bool operator>=(const stack& x, const stack& y) {
        //     return x.c >= y.c;
        // }
        // >> 진베거 보고 구현하기

        protected:
            container_type c;
        
        /* friend non member function for relational operators */
        // 멤버함수가 아니라서 class외부에 작성을 하였고, class외부에 작성을 하면 getter없이는 protected, private 변수에 접
        // 근을 할 수가 없는데 stack에는 getter가 없어서, friend 키워드를 통해서 class밖에 있는 다른 객체도 protected private에 접근 할 수
        // 있게 해주게 끔 하기위해 friend를 붙였다.

        // 이 두개 만 선언을 해주고 이 두개를 응용해서 만든다!

        // 템플릿 인자 하나를 없애면 이러한 오류
        // srcs/stack/relational_ope_list.cpp:14:30: error: invalid operands to binary expression
        // ('const ft::stack<int, std::list<int> >' and 'const ft::stack<int, std::list<int> >')
        
        // reference의 operator template구조가 아래와 같다. 
        template <class Tn, class Containern>
            friend bool operator== (const stack<Tn, Containern>& lhs, const stack<Tn, Containern>& rhs);
        template <class Tn, class Containern>
            friend bool operator<  (const stack<Tn,Containern>& lhs, const stack<Tn, Containern>& rhs);
    };

    template <class Tn, class Containern>  
	    bool operator== (const stack<Tn, Containern> & lhs, const stack<Tn, Containern> & rhs) { return (lhs.c == rhs.c); }
    template <class Tn, class Containern>
        bool operator<  (const stack<Tn, Containern> & lhs, const stack<Tn, Containern> & rhs) { return (lhs.c < rhs.c); }
    template <class Tn, class Containern>
        bool operator!= (const stack<Tn, Containern> & lhs, const stack<Tn, Containern> & rhs) { return !(lhs == rhs); }
    template <class Tn, class Containern>
        bool operator<= (const stack<Tn, Containern> & lhs, const stack<Tn, Containern> & rhs) { return !(rhs < lhs); }
    template <class Tn, class Containern>
        bool operator>  (const stack<Tn, Containern> & lhs, const stack<Tn, Containern> & rhs) { return (rhs < lhs); }
    template <class Tn, class Containern>
        bool operator>= (const stack<Tn, Containern> & lhs, const stack<Tn, Containern> & rhs) { return !(lhs < rhs); }

}
#endif