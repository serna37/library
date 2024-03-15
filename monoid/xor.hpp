#include <bits/stdc++.h>
using namespace std;
/**
 * 排他的論理和モノイド
 */
template <typename T> struct Mxor {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T op(const T &x, const T &y) noexcept {
        return x ^ y;
    }
};
