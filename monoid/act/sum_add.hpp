#include <bits/stdc++.h>
using namespace std;
/**
 * モノイド、作用素付きモノイド
 */
template <typename T> struct Madd {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T op(const T &x, const T &y) noexcept {
        return x + y;
    }
};
template <typename T> struct MAsumadd {
    using M_m = Madd<T>;
    using M_a = Madd<T>;
    using M = typename M_m::value_type;
    using A = typename M_a::value_type;
    static constexpr M act(const M &m, const A &a, const long long &size) {
        return m + a * T(size);
    }
};
