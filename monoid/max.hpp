#include <bits/stdc++.h>
using namespace std;
lib_others_inf
/**
 * 最大値モノイド
 */
template <typename T> struct Mmax {
    using value_type = T;
    static constexpr T e = -inf<T>;
    static constexpr T op(const T &x, const T &y) noexcept {
        return max(x, y);
    }
};
