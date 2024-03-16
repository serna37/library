#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1e9;
template <> constexpr long long inf<long long> = 1e18;
/**
 * 加算モノイド
 */
template <typename T> struct Madd {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T inverse(const T &x) noexcept {
        return -x;
    }
    static constexpr T op(const T &x, const T &y) noexcept {
        return x + y;
    }
};
/**
 * 代入モノイド
 */
template <typename T> struct Mset {
    using value_type = T;
    static constexpr T e = inf<T>; // 制約外であること
    static constexpr T op(const T &x, const T &y) noexcept {
        return y == e ? x : y;
    }
};
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
