#include <bits/stdc++.h>
using namespace std;
lib_others_inf
lib_monoid_add
lib_monoid_set
/**
 * 加算モノイドに対し、代入モノイドを右作用
 */
template <typename T> struct MAaddset {
    using M_m = Madd<T>;
    using M_a = Mset<T>;
    using M = typename M_m::value_type;
    using A = typename M_a::value_type;
    static constexpr M act(const M &m, const A &a, const long long &size) {
        (void)size; // unused
        if (a != inf<T>) {
            m = a * T(size);
        }
        return m;
    }
};
