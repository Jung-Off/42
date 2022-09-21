#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {

    // pair ================================================================================

    template <typename T1, typename T2>
    struct pair {
        typedef T1 first_type;
        typedef T2 second_type;

        // member variable
        first_type first;
        second_type second;

        /* constructor & destructor */
        pair(void) : first(first_type()), second(second_type()) {}

        pair(const first_type& x, const second_type& y) : first(x), second(y) {}
        
        template<typename U1, typename U2>
        pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

        // 구조체 소멸자!
        // 기본 소멸자가 호출이 될거 같아서 작성을 안한 것 같지만 통일감을 주기 위해서!
        ~pair(void) {}
        // assign operator
        pair& operator=(const pair& p) {
            if (this != &p) {
                first = p.first;
                second = p.second;
            }
            return *this;
        }
    };

    /* make_pair */
    // pair > int, char pair<int, char> 이런식
    // make_pair 는 타입이 자동으로 들어간다 make_pair(1, 'c');
    template <typename T1, typename T2>
    ft::pair <T1, T2> make_pair(T1 x, T2 y) {
        return pair<T1, T2>(x, y);
    }

    /* relational_operators */
    template <typename T1, typename T2>
    bool operator==(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
        return x.first == y.first && x.second == y.second;
    }

    template <typename T1, typename T2>
    bool operator!=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
        return !(x == y);
    }

    template <typename T1, typename T2>
    bool operator<(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
        return x.first < y.first || (!(x.first > y.first) && x.second < y.second);
    }

    template <typename T1, typename T2>
    bool operator<=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
        return !(y < x);
    }

    template <typename T1, typename T2>
    bool operator>(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
    return y < x;
    }

    template <typename T1, typename T2>
    bool operator>=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) {
    return !(x < y);
    }
}   // namespace ft

#endif