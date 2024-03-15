#include <bits/stdc++.h>
using namespace std;
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
