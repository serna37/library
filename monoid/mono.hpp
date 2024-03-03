#include <bits/stdc++.h>
using namespace std;
/**
 * カスタムモノイド
 */
template <typename T> struct Mono {
    using value_type = T;          // 要素型
    static constexpr T e = inf<T>; // 単位元
    static T op(const T &x, const T &y) noexcept {
        // 二項演算を定義
        return min(x, y);
    }
};
