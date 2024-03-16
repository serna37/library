#include <bits/stdc++.h>
using namespace std;
lib_monoid_add
/**
 * 加算モノイドに対し、加算モノイドを右作用
 */
template <typename T> struct MAaddadd {
    using M_m = Madd<T>;
    using M_a = Madd<T>;
    using M = typename M_m::value_type;
    using A = typename M_a::value_type;
    static constexpr M act(const M &m, const A &a, const long long &size) {
        return m + a * T(size);
    }
};
