#include <bits/stdc++.h>
using namespace std;
/**
 * 最小値モノイドに対し、代入モノイドを右作用
 */
template <typename T> struct MAminset {
    using M_m = Mmin<T>;
    using M_a = Mset<T>;
    using M = typename M_m::value_type;
    using A = typename M_a::value_type;
    static constexpr M act(const M &m, const A &a, const long long &size) {
        (void)size; // unused
        return a == inf<T> ? m : a;
    }
};
