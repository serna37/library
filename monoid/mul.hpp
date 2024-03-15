#include <bits/stdc++.h>
using namespace std;
/**
 * 乗算モノイド
 */
template <typename T> struct Mmul {
    using value_type = T;
    static constexpr T e = 1;
    static constexpr T inverse(const T &x) noexcept {
        return T(1) / x; // 逆元
    }
    static constexpr T op(const T &x, const T &y) noexcept {
        return x * y;
    }
};
